#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t, ca = 1;
  cin >> t;
  while(ca <= t) {
    ll n, k;
    cin >> n >> k;

    cout << "Case " << ca << ": ";
    ++ca;
    if(k > n) {
      cout << 0 << endl;
      continue;
    }

    ll ans = 1, m = n;
    for(ll i = 1; i <= k; i++) {
      ans *= m;
      --m;
    }

    ll r1 = k, r2 = n - k;
    if(r2 > r1) swap(r1, r2);

    ll ncr = 1, d = 1;
    for(ll i = n; i > r1; i--) ncr *= i;
    for(ll i = 1; i <= r2; i++) d *= i;

    ncr /= d;
    ans *= ncr;

    cout << ans << endl;
  }

	return 0;
}
