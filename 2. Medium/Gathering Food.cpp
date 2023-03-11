#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

char g[15][15];
pair <int, int> indx[27];
int x[] = {1, -1, 0, 0}, y[] = {0, 0, 1, -1};
int n, lv[15][15];

void bfs(int s, int t) {
  queue <pair<int,int>> q;
  q.push({indx[s].first, indx[s].second});
  memset(lv, -1, sizeof(lv));
  lv[indx[s].first][indx[s].second] = 0;
  g[indx[s].first][indx[s].second] = '.';
  while(!q.empty()) {
    int u1 = q.front().first, u2 = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int v1 = u1 + x[i], v2 = u2 + y[i];
      if(v1 >= n || v1 < 0 || v2 >= n || v2 < 0 || lv[v1][v2] != -1) continue;
      if(g[v1][v2] == '.' || g[v1][v2] - 'A' == t) {
        lv[v1][v2] = lv[u1][u2]+1;
        q.push({v1,v2});
        if(g[v1][v2] - 'A' == t) return;
      }
    }
  }
}

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    cin >> n;
    int ct = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> g[i][j];
        if(g[i][j] >= 'A' && g[i][j] <= 'Z') {
          int in = g[i][j]-'A';
          indx[in] = {i,j};
          ct++;
        }
      }
    }
    int ans = 0, ck = 0;
    for(int i = 0; i < ct-1; i++) {
      bfs(i, i+1);
      if(lv[indx[i+1].first][indx[i+1].second] == -1) ck = -1;
      ans += lv[indx[i+1].first][indx[i+1].second];
    }
    cout << "Case " << cs++ << ": ";
    if(ck == -1) cout << "Impossible" << endl;
    else cout << ans << endl;
  }

  return 0;
}
