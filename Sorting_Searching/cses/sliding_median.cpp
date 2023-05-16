#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;
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
    vi vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    queue<int> qu;
    ordered_multiset st;
    for (int i = 0; i < n; i++)
    {
        if (qu.size() == k)
        {
            int val = qu.front();
            cout << *st.find_by_order((k - 1) / 2) << " ";
            st.erase(st.find_by_order(st.order_of_key(val)));
            qu.pop();
        }
        qu.push(vec[i]);
        st.insert(vec[i]);
    }
    cout << *(st.find_by_order((k - 1) / 2)) << " ";
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