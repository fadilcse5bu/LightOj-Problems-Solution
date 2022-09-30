#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[16][1 << 16], ar[16][16], n;
int bitmask(int i, int mask)
{
  if(mask == (1 << n) - 1) return 0;
  if(dp[i][mask] != -1) return dp[i][mask];

  for(int j = 0; j < n; j++) {
    if((mask & (1 << j)) == 0) {
      dp[i][mask] = max(dp[i][mask], ar[i][j] + bitmask(i + 1, mask | (1 << j)));
    }
  }
  return dp[i][mask];
}

int main()
{
  int t, ca = 1;
  cin >> t;

  start:
  while(ca <= t) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> ar[i][j];
      }
    }

    memset(dp, -1, sizeof dp);
    cout << "Case " << ca << ": " << bitmask(0, 0) << endl;
    ++ca;
  }

	return 0;
}
