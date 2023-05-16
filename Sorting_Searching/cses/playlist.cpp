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
    ll n;
    cin >> n;
    vi vec(n + 1);
    map<int, int> lastocc;
    ll start_window = 0;
    ll ans = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        start_window = max(start_window, (ll)lastocc[vec[i]] + 1);
        ans = max(ans, i - start_window + 1);
        lastocc[vec[i]] = i;
    }
    cout << ans << "\n";
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

// #include <bits/stdc++.h>

// using namespace std;
// typedef long long int ll;
// typedef vector<ll> vi;
// typedef vector<vi> vvi;
// typedef pair<int, int> pa;
// typedef vector<pa> vp;
// #define pb push_back
// #define sz(a) (int)(a.size())
// #define endl "\n"
// #define speed                         \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(nullptr);                 \
//     cout.tie(nullptr);

// void solve()
// {
//     ll n;
//     cin >> n;
//     vi vec(n);
//     set<ll> si;
//     map<ll, int> mp;
//     deque<int> dq;
//     ll maxans = -1;
//     ll fins;
//     vi cpyvec(n);
//     for(int i=0;i<n;i++) cin >> vec[i],cpyvec[i] = vec[i];
//     sort(cpyvec.begin(),cpyvec.end());
//     if(cpyvec[0] == cpyvec[n - 1]) cout << "1\n";
//     else{
//     for (int i = 0; i < n; i++)
//     {
//         cin >> vec[i];
//         if (si.size() == 0) fins = vec[i];
//         int prevsz = si.size();
//         si.insert(vec[i]);
//         dq.push_back(vec[i]);
//         int aftersz = si.size();
//         if (prevsz == aftersz)
//         {
//             // dq.pop_back();
//             if (vec[i] != fins)
//             {
//                 si.clear();
//                 if(dq.size()) dq.clear();
//             }
//             else
//             {
//                 if(dq.size()) dq.pop_front();
//                 si.erase(si.find(vec[i]));
//                 if(dq.size()) fins = dq.front();
//                 else fins = vec[i];
//             }
//             if (si.size() == 0) fins = vec[i];
//             si.insert(vec[i]);
//             dq.push_back(vec[i]);
//         }
//         mp[vec[i]] = i;
//         maxans = max((ll)si.size(), maxans);
//     }
//     cout << maxans << "\n";}
// }

// int main()
// {
//     speed;
//     ll tc = 1;
//     // cin >> tc;
//     while (tc--)
//     {
//         solve();
//     }
//     return 0;
// }