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
    ll n, m;
    cin >> n >> m;
    vi vec(n + 1);
    vi ind(n + 3, 0);
    ind[0] = 0;
    ind[n + 1] = n + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        ind[vec[i]] = i;
    }
    int cnt = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        cnt += (ind[i] > ind[i + 1]);
    }
    for (int i = 1; i <= m; i++)
    {
        int pos1, pos2;
        cin >> pos1 >> pos2;
        int fval = vec[pos1];
        int sval = vec[pos2];
        // need to swap fval and sval
        if (ind[fval - 1] > ind[fval])
        {
            cnt--;
        }
        if (ind[fval] > ind[fval + 1])
        {
            cnt--;
        }
        if (ind[sval - 1] > ind[sval] && sval - 1 != fval)
        {
            cnt--;
        }
        if (ind[sval] > ind[sval + 1] && sval + 1 != fval)
        {
            cnt--;
        }
        ind[fval] = pos2;
        ind[sval] = pos1;
        swap(vec[pos1], vec[pos2]);
        if (ind[fval - 1] > ind[fval])
        {
            cnt++;
        }
        if (ind[fval] > ind[fval + 1])
        {
            cnt++;
        }
        if (ind[sval - 1] > ind[sval] && sval - 1 != fval)
        {
            cnt++;
        }
        if (ind[sval] > ind[sval + 1] && sval + 1 != fval)
        {
            cnt++;
        }
        cout << cnt << "\n";
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