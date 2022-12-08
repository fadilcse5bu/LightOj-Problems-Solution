#include <bits/stdc++.h>
using namespace std;

vector <int> G[200005];
bool vis[200005], isAp[200005];
int  dis_time = 0, low[200005], dis[200005];

void dfs(int u, int par) {
  int children = 0;
  vis[u] = 1;
  low[u] = dis[u] = ++dis_time;
  for(auto v: G[u]) {
    if(!vis[v]) {
      ++children;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if(par != -1 && low[v] >= dis[u])
        isAp[u] = true;
    }
    else if(v != par)
      low[u] = min(low[u], dis[v]);
  }
  if(par == -1 && children > 1)
    isAp[u] = true;
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
      G[i].clear();
      vis[i] = 0;
      isAp[i] = false;
    }
    for(int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
      if(!vis[i]) dfs(i, -1);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
      if(isAp[i] == true) ++ans;

    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
