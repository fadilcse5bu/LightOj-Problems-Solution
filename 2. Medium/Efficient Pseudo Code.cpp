#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9+7;

ll mod_pow(ll b, ll p) {
  if(p == 0) return 1;
  if(p % 2 == 1) return (b * mod_pow(b, p-1))%mod;
  else {
    ll temp = mod_pow(b, p/2) % mod;
    return (temp * temp) % mod;
  }
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    ll n, m;
    cin >> n >> m;
    vector <pair<ll, ll>> prime;
    prime.push_back({2, 1});
    for(ll i = 2; i <= sqrt(n); i++) {
      ll ct = 0;
      while(n % i == 0) {
        ++ct;
        n /= i;
      }
      if(ct) prime.push_back({i, ct*m+1});
    }
    if(n != 1) prime.push_back({n, m+1});

    ll ans = 1;
    for(int i = 0; i < prime.size(); i++) {
      ll pow_val = mod_pow(prime[i].first, prime[i].second);
      pow_val = (pow_val - 1 + mod) % mod;
      ll den = mod_pow(prime[i].first - 1, mod-2);
      ans = (((ans * pow_val)%mod) * den) % mod;
    }

    cout << "Case " << cs++ << ": " << ans << endl;
  }
}
