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

void gen_window(vi &start, vi &end, vi &vec, int n, int x)
{
    int gcdval = 0;
    int startidx = 0, endidx;
    while (startidx < n)
    {
        if (vec[startidx] % x != 0) startidx++;
        else
        {
            endidx = startidx;
            while (endidx < n - 1 && vec[endidx + 1] % x == 0) endidx++;
            start.pb(startidx);
            end.pb(endidx);
            startidx = endidx + 1;
        }
    }
}

int subArrfunc(vector<int> arr, int n, int x)
{
    vi start_indices;
    vi end_indices;
    gen_window(start_indices, end_indices, arr, n, x);
    int ans = -1;
    for (int i = 0; i < start_indices.size(); i++)
    {
        int startidx = start_indices[i];
        int endidx = end_indices[i];
        int counter = 0;
        int curr_gcd = 0;
        for (int j = startidx; j <= endidx; j++)
        {
            curr_gcd = __gcd(arr[j], curr_gcd);
            if (curr_gcd == x)
            {
                counter++;
                curr_gcd = 0;
            }
        }
        ans = max(ans, counter);
    }
    return ans;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << subArrfunc(arr, n, x) << "\n";
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