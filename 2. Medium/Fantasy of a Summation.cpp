#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll power(ll b, ll p, ll mod) {
  if(p == 0) return 1;
  if(p%2 == 1) return (b*power(b, p-1, mod))%mod;
  else {
    ll temp = power(b, p/2, mod);
    return (temp*temp)%mod;
  }
}

int main()
{
  int t, cs = 1;
  cin >> t;
  start:
  while(t--) {
    ll n, k, mod; cin >> n >> k >> mod;
    ll v = (k*power(n, k-1, mod))%mod;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
      ll a; cin >> a;
      ans = (ans + a*v)%mod;
    }
    cout << "Case "<< cs++ << ": " << ans << endl;
  }

  return 0;
}
