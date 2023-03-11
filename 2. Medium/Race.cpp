#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int const N = 1005;
ll dp[N], ncr[N][N], sNcr[N], mod = 10056;

/// main idea, ncr(x,y) = ncr(x-1,y-1) + ncr(x-1,y);
void find_ncr() {
  ncr[1][0] = ncr[1][1] = 1;
  for(ll i = 2; i < N; i++) {
    ncr[i][0] = ncr[i][i] = 1;
    for(ll j = 1; j < i; j++) {
      ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%mod;
    }
  }
}

ll cal(ll n) {
  if(n == 0) return 1;
  if(dp[n] != -1) return dp[n];
  ll ct = 0;
  for(ll i = 1; i <= n; i++) {
    ct = (ct + (ncr[n][i]*cal(n-i)))%mod;
  }
  return dp[n] = ct;
}

int main()
{
  find_ncr();
  memset(dp, -1, sizeof(dp));
  int t, cs = 1;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    ll ans = cal(n);
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
