#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1000003;
ll fact[1000005];

ll module_inverse(ll b, ll p) {
  if(p == 0) return 1;
  if(p % 2 == 1) return (b* module_inverse(b, p-1)) % mod;
  else {
    ll temp = module_inverse(b, p/2);
    return (temp * temp) % mod;
  }
}

int main()
{

  fact[0] = 1;
  for(ll i = 1; i <= 1000000; i++) {
    fact[i] = (fact[i-1] * i) % mod;
  }
  int t, cs = 1;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    ll v = (fact[k] * fact[n-k])%mod;
    ll ans = fact[n] * (module_inverse(v, mod-2));
    cout << "Case " << cs++ << ": " << ans%mod << endl;
  }
}
