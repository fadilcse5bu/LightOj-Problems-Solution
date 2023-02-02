#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll n, m;
    cin >> n >> m;
    ll lf[m];
    for(int i = 0; i < m; i++) cin >> lf[i];

    ll ans = n;
    for(ll i = 1; i < (1 << m); i++) {
      ll lcm = 1, ct = 0;
      for(ll j = 0; j < m; j++) {
        if(i & (1 << j)) {
          ++ct;
          ll gcd = __gcd(lcm, lf[j]);
          lcm = (lcm*lf[j]) / gcd;
          if(lcm > n) break;
        }
      }
      ll d = n / lcm;
      if(ct & 1) ans -= d;
      else ans += d;
    }
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
