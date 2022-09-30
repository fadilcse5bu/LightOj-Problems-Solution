#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, m, dp[(1<<16)+10][20];
vector <pair<int, int>> grid;

int distances(int p1, int p2) {
  return max(abs(grid[p1].first - grid[p2].first), abs(grid[p1].second - grid[p2].second));
}

int cal(int mask, int pre) {
  if(mask == ((1 << n) - 1)) return distances(pre, 0);
  if(dp[mask][pre] != -1) return dp[mask][pre];
  int res = INT_MAX;
  for(int i = 0; i < n; i++) {
    if(!(mask&(1<<i))) {
      int v = cal(mask|(1<<i), i) + distances(pre, i);
      res = min(res, v);
    }
  }

  return dp[mask][pre] = res;
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    grid.clear();
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        char ch;
        cin >> ch;
        if(ch == 'g' or ch == 'x') {
          grid.push_back({i, j});
        }
      }
    }
    n = grid.size();
    cout << "Case " << cs++ << ": " << cal(1, 0) << endl;
  }
}
