#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long  
const ll INF_MUL=1e13;
const ll INF_ADD=1e18;  
#define pb push_back               
#define mp make_pair        
#define nline "\n"                           
#define f first                                          
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()   
#define vl vector<ll>         
#define vvl vector<vector<ll>>    
#define vvvl vector<vector<vector<ll>>>          
#ifndef ONLINE_JUDGE    
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<nline;
#else
#define debug(x);  
#endif     
void _print(ll x){cerr<<x;}  
void _print(char x){cerr<<x;} 
void _print(string x){cerr<<x;}     
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";} 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const ll MOD=998244353;   
const ll MAX=500500;
ll target,atleast=0;
vector<vector<ll>> adj;
vector<ll> depth(MAX,0),use(MAX,0);
void dfs_1(ll cur,ll par){
    for(auto chld:adj[cur]){
        if(chld!=par){
            depth[chld]=depth[cur]+1;   
            dfs_1(chld,cur);     
        }
    }        
}         
void dfs_2(ll cur,ll par){     
    use[cur]=depth[cur];
    // cout << use[cur] << " " << cur << "**\n";
    for(auto chld:adj[cur]){    
        if(chld!=par){       
            dfs_2(chld,cur);       
            use[cur]=max(use[cur],use[chld]);
        }
    }
    if(par>1){
        if(use[cur]-depth[cur]==target-1){ 
            use[cur]=0; atleast++;
        }
    }
}  
void solve(){       
    ll n,k; cin>>n>>k;
    adj.clear(); adj.resize(n+5);
    for(ll i=2;i<=n;i++){
        ll u=i,v; cin>>v;   
        adj[u].pb(v); adj[v].pb(u);  
    }
    ll l=1,r=n-1,ans=n-1;
    dfs_1(1,-1);
    while(l<=r){
        target=(l+r)/2,atleast=0;
        dfs_2(1,-1);
        if(atleast<=k){
            ans=target;
            r=target-1;
        }
        else{
            l=target+1;
        }
    }
    cout<<ans<<nline;
    return;                   
}                                 
int main()                                                                         
{
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);                                
    ll test_cases=1;                   
    cin>>test_cases;
    while(test_cases--){   
        solve();       
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"; 
} 