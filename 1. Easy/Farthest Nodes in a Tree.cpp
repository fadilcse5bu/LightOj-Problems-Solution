#include <bits/stdc++.h>
using namespace std;

bool col[30001];
vector <int> G[30001], W[30001];
int ans = 0, cost[30001], par[30001];

void Clear() {
  for(int i = 0; i <= 30000; i++) {
    G[i].clear();
    W[i].clear();
    col[i] = false;
    cost[i] = 0;
    par[i] = 0;
    ans = 0;
  }
}

void dfs(int x) {
  col[x] = true;
  for(int i = 0; i < G[x].size(); i++) {
    if(col[G[x][i]] == false) {
      par[G[x][i]] = x;
      cost[G[x][i]] = W[x][i];
      dfs(G[x][i]);
    }
  }

  int a = 0, b = 0;
  for(int i = 0; i < G[x].size(); i++) {
    if(par[x] != G[x][i]) {
      if(cost[G[x][i]] > b) {
        a = b;
        b = cost[G[x][i]];
      }
      else if(cost[G[x][i]] > a) a = cost[G[x][i]];
    }
  }
  cost[x] += b;
  ans = max(ans, a+b);
}

int main()
{
  int t, tc = 1;
  cin >> t;
  while(t--) {
    Clear();
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      G[u].push_back(v);
      G[v].push_back(u);
      W[u].push_back(w);
      W[v].push_back(w);
    }
    dfs(0);
    cout << "Case " << tc++ << ": " << ans << endl;
  }

  return 0;
}
