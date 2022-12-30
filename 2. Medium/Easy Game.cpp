#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, ar[105], dp[105][105][2];

int go(int l, int r, int tp) {
  if(l > r) return 0;
  if(dp[l][r][tp] != -1) return dp[l][r][tp];
  int sum, v;
  if(tp == 0) {
    sum = 0, v = INT_MIN;
    for(int i = l; i <= r; i++) {
      sum += ar[i];
      v = max(v, sum + go(i+1, r, 1));
    }
    sum = 0;
    for(int i = r; i >= l; i--) {
      sum += ar[i];
      v = max(v, sum + go(l, i-1, 1));
    }
    return dp[l][r][tp] = v;
  }
  else {
    sum = 0, v = INT_MAX;
    for(int i = l; i <= r; i++) {
      sum -= ar[i];
      v = min(v, sum + go(i+1, r, 0));
    }
    sum = 0;
    for(int i = r; i >= l; i--) {
      sum -= ar[i];
      v = min(v, sum + go(l, i-1, 0));
    }
    return dp[l][r][tp] = v;
  }
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> ar[i];
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= n; j++) {
        dp[i][j][0] = -1;
        dp[i][j][1] = -1;
      }
    }
    int ans = go(0, n-1, 0);
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
