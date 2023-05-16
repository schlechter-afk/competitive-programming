#include <bits/stdc++.h>
using namespace std;

// dp[x] = minimum number of operations to go from x to zero.
// dp[x] = min dp[x-d] where d belongs to digits(x)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (char c : to_string(i))
        {
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }
    cout << dp[n] << endl;
}