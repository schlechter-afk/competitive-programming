#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pa;
typedef vector<pa> vp;
#define pb push_back
#define sz(a) (int)(a.size())
#define endl "\n"
#define mod 1000000007
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void solve()
{
    ll n, m;
    cin >> n >> m;
    vi values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    ll cnt = 1;
    vi multi;
    for (int i = 0; i < n; i++)
    {
        if (values[i] == 0)
        {
            if (i > 0 && i < n - 1 && values[i - 1] > 0 && values[i + 1] > 0)
            {
                ll val = 0;
                set<int> sa;
                sa.insert(values[i - 1]);
                sa.insert(values[i - 1] + 1);
                sa.insert(values[i - 1] - 1);
                if (sa.find(values[i + 1]) != sa.end() && values[i + 1] <= m && values[i + 1] >= 0)
                {
                    val++;
                }
                if (sa.find(values[i + 1] + 1) != sa.end() && values[i + 1] + 1 <= m && values[i + 1] + 1 >= 0)
                {
                    val++;
                }
                if (sa.find(values[i + 1] - 1) != sa.end() && values[i + 1] - 1 <= m && values[i + 1] - 1 >= 0)
                {
                    val++;
                }
                multi.push_back(val);
            }
            else if (i == n - 1 && values[i - 1] > 0)
            {
                ll val = 0;
                set<int> sa;
                sa.insert(values[i - 1]);
                sa.insert(values[i - 1] + 1);
                sa.insert(values[i - 1] - 1);
                if (values[i - 1] <= m && values[i - 1] >= 0)
                {
                    val++;
                }
                if (values[i - 1] + 1 <= m && values[i - 1] + 1 >= 0)
                {
                    val++;
                }
                if (values[i - 1] - 1 <= m && values[i - 1] - 1 >= 0)
                {
                    val++;
                }
                multi.push_back(val);
            }
            else if (i == 0 && values[i + 1] > 0)
            {
                ll val = 0;
                set<int> sa;
                sa.insert(values[i + 1]);
                sa.insert(values[i + 1] + 1);
                sa.insert(values[i + 1] - 1);
                if (values[i + 1] <= m && values[i + 1] >= 0)
                {
                    val++;
                }
                if (values[i + 1] + 1 <= m && values[i + 1] + 1 >= 0)
                {
                    val++;
                }
                if (values[i + 1] - 1 <= m && values[i + 1] - 1 >= 0)
                {
                    val++;
                }
                multi.push_back(val);
            }
            else if (i > 0 && i < n - 1 && values[i - 1] > 0 && values[i + 1] == 0)
            {
                ll val = 0;
                set<int> sa;
                sa.insert(values[i - 1]);
                sa.insert(values[i - 1] + 1);
                sa.insert(values[i - 1] - 1);
                int cpyi = i;
                while (cpyi < n && values[cpyi] == 0)
                {
                    cpyi++;
                }
                ll diff = cpyi - i;
                if (cpyi != n)
                {
                    
                }
            }
        }
    }
    for (int i = 0; i < multi.size(); i++)
    {
        cnt *= multi[i];
        cnt %= mod;
    }
    cout << cnt << endl;
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