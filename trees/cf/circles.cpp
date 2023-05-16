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
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    map<int, set<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]].insert(i);
    }

    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            int id1 = *m[b[i]].begin();
            ans.push_back({i, id1});
            ans.push_back({id1, i});
            ans.push_back({i, id1});
            m[a[id1]].erase(id1);
            m[a[i]].erase(i);
            swap(a[id1], a[i]);
            m[a[id1]].insert(id1);
            m[a[i]].insert(i);
        }
        m[a[i]].erase(i);
    }
    cout << sz(ans) << endl;
    for (auto &c : ans)
    {
        cout << c.first + 1 << " " << c.second + 1 << endl;
    }
}

int main()
{
    speed;
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}