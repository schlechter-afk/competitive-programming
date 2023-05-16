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

void solve()
{
    ll n, x;
    cin >> n >> x;
    vp vec(n);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        vec[i] = {val, i};
    }
    sort(vec.begin(), vec.end());
    int ptr1 = 0, ptr2 = n - 1;
    while (ptr1 < ptr2)
    {
        if (vec[ptr1].first + vec[ptr2].first < x)
        {
            ptr1++;
        }
        else if (vec[ptr1].first + vec[ptr2].first > x)
        {
            ptr2--;
        }
        else
        {
            cout << vec[ptr1].second + 1 << " " << vec[ptr2].second + 1 << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
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