#include "bits/stdc++.h"
using namespace std;
const int MN = 1e5 + 10;
 
int N, M, ans, rep[MN];
std::vector<int> adj_list[MN];
bool visited[MN];
 
void dfs(int node)
{
    visited[node] = true;
    for (int u : adj_list[node])
        if (!visited[u])
            dfs(u);
}
int count_components()
{
    int count = 0;
    for (int i = 1; i <= N; ++i)
        if (!visited[i])
        {
            rep[count++] = i;
            dfs(i);
        }
    return count;
}
 
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    scanf("%d%d", &N, &M);
    for (int i = 0, u, v; i < M; ++i)
        scanf("%d%d", &u, &v), adj_list[u].push_back(v), adj_list[v].push_back(u);
    ans = count_components();
    printf("%d\n", ans - 1);
    for (int i = 1; i < ans; ++i)
        printf("%d %d\n", rep[i - 1], rep[i]);
    return 0;
}