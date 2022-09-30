#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool prime[1000005];
vector <ll> prime_value;

void sieve() {
  for(int i = 3; i*i <= 1000002; i += 2) {
    if(prime[i] == false) {
      for(int j = i * i; j <= 1000002; j += (2 * i)) {
        prime[j] = true;
      }
    }
  }
  prime_value.push_back(2);
  for(int i = 3; i <= 1000002; i += 2) {
    if(prime[i] == false) {
      prime_value.push_back(i);
    }
  }
}

int main()
{
  sieve();
  int t, tc = 1;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    ll ans = 1;
    for(int i = 0; i < prime_value.size() && prime_value[i] * prime_value[i] <= n; i++) {
      ll ct = 1;
      while(n % prime_value[i] == 0) {
        ++ct;
        n /= prime_value[i];
      }
      ans *= ct;
    }
    if(n != 1) ans *= 2;

    cout << "Case " << tc++ << ": " << ans - 1 << endl;
  }

  return 0;
}
