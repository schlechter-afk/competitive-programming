#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pa;
typedef vector<pa> vp;
#define pb push_back
#define sz(a) (int)(a.size())
#define endl "\n"
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

struct minQueue
{
    stack<pair<ll, ll>> front, back; // front for pushing new elements, back for removing elements

    void push(ll val)
    {
        if (!front.size())
        {
            front.push({val, val});
            return;
        }
        front.push({val, min(val, (ll)front.top().second)});
    }

    void pop()
    {
        if (!back.size())
        {
            while (!front.empty())
            {
                if (back.empty())
                {
                    back.push({front.top().first, front.top().first});
                    front.pop();
                }
                else
                {
                    back.push({front.top().first, (ll)min(front.top().first, back.top().second)});
                    front.pop();
                }
            }
            back.pop();
        }
        else
        {
            back.pop();
        }
    }

    ll minvalue()
    {
        if (front.empty())
            return (ll)back.top().second;
        if (back.empty())
            return (ll)front.top().second;
        return (ll)min(front.top().second, back.top().second);
    }
};

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vi vec(n + 1, 0);
    vi prefsum(n + 1, 0);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        prefsum[i] = prefsum[i - 1] + vec[i];
    }

    minQueue qu;
    ll ans = -2e18;
    for (int i = a; i <= n; i++)
    {
        if (i > b) qu.pop();
        qu.push(prefsum[i - a]);
        ans = max(ans, (ll)prefsum[i] - qu.minvalue());
    }
    cout << ans;
}

int main()
{
    speed;
    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}