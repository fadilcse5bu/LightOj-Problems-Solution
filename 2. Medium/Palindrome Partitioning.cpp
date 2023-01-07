#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll h[1001], rh[1001], p[1001], base = 29, n, mod = 1e9+7;
ll dp[1001];

ll cntPalin(int indx) {
  if(indx > n) return 0;
  if(dp[indx] != -1) return dp[indx];
  ll v = INT_MAX;
  for(int i = indx; i <= n; i++) {
    ll v1 = (h[i] - ((h[indx-1]*p[i-indx+1])%mod) + mod)%mod;
    ll v2 = (rh[indx-1] - ((rh[i]*p[i-indx+1])%mod) + mod)%mod;
    if(v1 == v2) {
      v = min(v, 1 + cntPalin(i+1));
    }
  }
  return dp[indx] = v;
}

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    string st, rst;
    cin >> st;
    n = st.size();
    h[0] = 0, rh[n] = 0, p[0] = 1;
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++) {
      h[i] = (h[i-1]*base + (st[i-1]-'A'+1))%mod;
      p[i] = (p[i-1]*base)%mod;
    }
    for(int i = n-1; i >= 0; i--) {
      rh[i] = (rh[i+1]*base + (st[i]-'A'+1))%mod;
    }
    ll ans = cntPalin(1);
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}


