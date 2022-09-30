#include <bits/stdc++.h>
using namespace std;

vector <int> edges[10005], order;
bool vis[10005];

void dfs1(int x) {
  vis[x] = true;
  for(int i = 0; i < edges[x].size(); i++) {
    if(vis[edges[x][i]] == false) dfs1(edges[x][i]);
  }
  order.push_back(x);
}

void dfs2(int x) {
  vis[x] = true;
  for(int i = 0; i < edges[x].size(); i++) {
    if(vis[edges[x][i]] == false) dfs2(edges[x][i]);
  }
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int n, e;
    cin >> n >> e;
    for(int i = 0; i <= n; i++) edges[i].clear();
    while(e--) {
      int u, v;
      cin >> u >> v;
      edges[u].push_back(v);
    }
    order.clear();
    memset(vis, false, sizeof vis);
    for(int i = 1; i <= n; i++) {
      if(vis[i] == false) {
        dfs1(i);
      }
    }

    reverse(order.begin(), order.end());
    memset(vis, false, sizeof vis);
    int ans = 0;
    for(int i = 0; i < order.size(); i++) {
      if(!vis[order[i]]) {
        ++ans;
        dfs2(order[i]);
      }
    }

    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
