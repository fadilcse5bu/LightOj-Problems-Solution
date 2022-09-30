#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
char adj[11][11];
int mov[11][11], rider[11][11], cnt[11][11];

bool isValidCell(int x, int y, int n, int m) {
  if(x < 0 || x >= n) return false;
  if(y < 0 || y >= m) return false;
  return true;
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> adj[i][j];
        rider[i][j] = 0;
        cnt[i][j] = 0;
      }
    }

    int ct = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(adj[i][j] != '.') {
          ++ct;
          for(int k = 0; k < n; k++) {
            for(int l = 0; l < m; l++) {
              mov[k][l] = -1;
            }
          }
          int v = adj[i][j] - '0';
          queue <pair<pair<int, int>, int>> q;
          q.push({{i, j}, 0});
          mov[i][j] = 0;
          while(!q.empty()) {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            for(int k = 0; k < 8; k++) {
              int x = p.first.first + dx[k], y = p.first.second + dy[k];
              if(isValidCell(x, y, n, m)) {
                int val = p.second + 1;
                if(mov[x][y] == -1 || val < mov[x][y]) {
                  mov[x][y] = val;
                  q.push({{x, y}, val});
                }
              }
            }
          }
          for(int k = 0; k < n; k++) {
            for(int l = 0; l < m; l++) {
              if(mov[k][l] != -1) {
                cnt[k][l]++;
                int val = mov[k][l] / v;
                if(mov[k][l] % v != 0) ++val;
                rider[k][l] += val;
              }
            }
          }
        }
      }
    }
    int ans = -1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(cnt[i][j] == ct) {
          if(ans == -1) ans = rider[i][j];
          else ans = min(ans, rider[i][j]);
        }
      }
    }

    cout << "Case " << cs++ << ": " << ans << endl;
  }

	return 0;
}

