#include <bits/stdc++.h>
using namespace std;

bool vis[505][505];
double dp[505][505];

double cal(int r, int b) {
  if(b < 0) return 0.0;
  if(r == 0) {
    if(b&1) return dp[r][b] = 1.0;
    else return dp[r][b] = 0.0;
  }
  if(vis[r][b]) return dp[r][b];
  vis[r][b] = 1;
  if(b == 0) return dp[r][b] = 0.0;
  double res = (r*1.0/(r+b)) * cal(r-1, b-1) +  (b*1.0/(r+b)) * cal(r, b - 2);
  return dp[r][b] = res;
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int r, b;
    cin >> r >> b;
    cout << "Case " << cs++ << ": " << fixed << setprecision(12) << cal(r, b) << endl;
  }
}
