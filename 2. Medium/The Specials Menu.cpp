#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string W;
long long int dp[65][65];

long long int findP(int l, int r) {
  if(l > r) return 0;
  if(dp[l][r] != -1) return dp[l][r];
  if(l == r) return dp[l][r] = 1;
  if(W[l] == W[r]) {
    return dp[l][r] = 1 + findP(l+1,r-1) + findP(l+1, r) + findP(l,r-1) - findP(l+1,r-1);
  }
  else {
    return dp[l][r] = findP(l+1, r) + findP(l,r-1) - findP(l+1,r-1);
  }
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    cin >> W;
    int len = W.size();
    for(int i = 0; i <= len; i++) {
      for(int j = 0; j <= len; j++) {
        dp[i][j] = -1;
      }
    }
    long long int ans = findP(0, len-1);
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
