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
    ll n, k;
    cin >> n >> k;
    vp times(n);
    // times[i].first is endtime and .second is starttime.
    for (int i = 0; i < n; i++)
    {
        cin >> times[i].second >> times[i].first;
    }
    sort(times.begin(), times.end());
    multiset<ll> ms; // storing end times of movies.
    ll movies = 0;
    for (int i = 0; i < k; i++)
        ms.insert(0);
    for (int i = 0; i < n; i++)
    {
        auto itr = ms.upper_bound(times[i].second);
        // cout << times[i].second << " " << times[i].first << " " << *itr << " \n";
        if (itr == ms.begin())
        {
            // cout << times[i].second << " " << times[i].first << " " << *itr << " \n";
            continue;
        }
        itr--;
        ms.erase(itr);
        // cout << *itr << "\n";
        ms.insert(times[i].first);
        movies++;
    }
    cout << movies;
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