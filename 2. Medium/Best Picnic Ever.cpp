#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    int k, n, m; cin >> k >> n >> m;
    int p[k]; vector <int> edg[n+1];
    for(int i = 0; i < k; i++) cin >> p[i];
    for(int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      edg[u].push_back(v);
    }
    int cnt[n+1] = {0};
    for(int i = 0; i < k; i++) {
      queue <int> q;
      q.push(p[i]);
      int col[n+1] = {0};
      col[p[i]] = 1;
      while(!q.empty()) {
        int u = q.front();
        q.pop();
        cnt[u]++;
        for(int j = 0; j < edg[u].size(); j++) {
          if(col[edg[u][j]] == 0) {
            q.push(edg[u][j]);
            col[edg[u][j]] = 1;
          }
        }
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      if(cnt[i] == k) ++ans;
    }
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
