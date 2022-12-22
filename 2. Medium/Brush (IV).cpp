#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int x[20],y[20], n, cPoints[20][20], dp[(1 << 17)];
int popCount(unsigned x) {
  x -= ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x + (x >> 4)) & 0x0F0F0F0F;
  x += (x >> 8);
  x += (x >> 16);
  return x & 0x0000003F;
}
int findLines(int mask) {
  if(dp[mask] != -1) return dp[mask];
  if(mask == (1 << n) - 1) return dp[mask] = 0;
  int cnt = popCount(mask);
  if(cnt == n-1 || cnt == n-2) return dp[mask] = 1;
  int ans = 8;
  for(int i = 0; i < n; i++) {
    if(mask & (1 << i)) continue;
    for(int j = i+1; j < n; j++) {
      if(mask & (1 << j)) continue;
      ans = min(ans, findLines(mask | cPoints[i][j]) + 1);
    }
    break;
  }
  return dp[mask] = ans;
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        if(i == j) continue;
        int mask = 0;
        mask |= (1 << i);
        mask |= (1 << j);
        for(int k = 0; k < n; k++) {
          int temp1 = x[i]*y[j]+x[j]*y[k]+x[k]*y[i];
          int temp2 = x[j]*y[i]+x[k]*y[j]+x[i]*y[k];
          if(temp1 == temp2) {
            mask |= (1 << k);
          }
        }
        cPoints[i][j] = mask;
      }
    }
    memset(dp, -1, sizeof dp);
    int ans = findLines(0);
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
