#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1, cs = 1;
	cin >> t;
	while (t--) {
    ll n, q; cin >> n >> q;
    ll ar[n+1], fx = 0;
    for(ll i = 1; i <= n; i++) {
      cin >> ar[i];
      fx += (ar[i]*(1-i) + ar[i]*(n-i));
    }
    cout << "Case " << cs++ << ":" << endl;
    while(q--) {
      ll typ; cin >> typ;
      if(typ == 1) cout << fx << endl;
      else {
        ll i, v; cin >> i >> v;
        ++i;
        fx -= (ar[i]*(1-i) + ar[i]*(n-i));
        ar[i] = v;
        fx += (ar[i]*(1-i) + ar[i]*(n-i));
      }
    }
	}

	return 0;
}
