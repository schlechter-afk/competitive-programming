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

void multiset_insert(ll val, multiset<ll> &lower, multiset<ll> &higher, ll k, ll &sumHigher, ll &sumLower)
{
    ll lim = *lower.rbegin();
    // insert into lower subgroup
    if (val < *lower.rbegin())
    {
        lower.insert(val);
        sumLower += val;
        if (lower.size() > ((k + 1) / 2))
        {
            higher.insert(*lower.rbegin());
            sumHigher += (*lower.rbegin());
            sumLower -= (*lower.rbegin());
            lower.erase(lower.find(*lower.rbegin()));
        }
    }
    else // insert into higher subgroup
    {
        higher.insert(val);
        sumHigher += val;
        if (higher.size() > (k / 2))
        {
            lower.insert(*higher.begin());
            sumLower += (*higher.begin());
            sumHigher -= (*higher.begin());
            higher.erase(higher.find(*higher.begin()));
        }
    }
}

void multiset_delete(ll val, multiset<ll> &lower, multiset<ll> &higher, ll &sumHigher, ll &sumLower)
{
    if (higher.find(val) != higher.end())
    {
        sumHigher -= val;
        higher.erase(higher.find(val));
    }
    else
    {
        sumLower -= val;
        lower.erase(lower.find(val));
    }
    if (lower.empty())
    {
        lower.insert(*higher.begin());
        sumLower += (*higher.begin());
        sumHigher -= (*higher.begin());
        higher.erase(higher.find(*higher.begin()));
    }
}

ll med(multiset<ll> &lower, ll k)
{
    if (k % 2) return (*lower.rbegin());
    return 0;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vi vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "0 ";
        }
        return;
    }
    ll sumHigher = 0;
    ll sumLower = 0;
    multiset<ll> lower;
    multiset<ll> higher;
    lower.insert(vec[0]);
    sumLower += vec[0];
    vi output;
    for (int i = 1; i < k; i++)
    {
        multiset_insert(vec[i], lower, higher, k, sumHigher, sumLower);
    }
    output.pb(sumHigher - sumLower + med(lower, k));
    for (int i = k; i < n; i++)
    {
        multiset_delete(vec[i - k], lower, higher, sumHigher, sumLower);
        multiset_insert(vec[i], lower, higher, k, sumHigher, sumLower);
        output.pb(sumHigher - sumLower + med(lower, k));
    }
    for (auto val : output)
    {
        cout << val << " ";
    }
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