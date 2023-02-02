#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll n; cin >> n;
    ll p[n][n];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) cin >> p[i][j];
    }

    ll dp[(1<<n)];
    dp[0] = 0;
    for(ll mask = 1; mask < (1 << n); mask++) {
      ll mn = INT_MAX;
      for(ll i = 0; i < n; i++) {
        if(mask & (1<<i)) {
          ll sum = dp[mask ^ (1<<i)];
          for(int j = 0; j < n; j++) {
            if(mask & (1 << j)) sum += p[i][j];
          }
          mn = min(mn, sum);
        }
      }
      dp[mask] = mn;
    }

    cout << "Case " << cs++ << ": " << dp[(1<<n)-1] << endl;
  }

  return 0;
}
