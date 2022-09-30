#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll f[2][2], mod = 1000000007;
void matrix_exponent(ll n) {
  if(n <= 1) return;
  if(n % 2) {
    matrix_exponent(n-1);
    ll v = (f[0][0] + f[0][1]) % mod;
    f[1][1] = f[0][1];
    f[1][0] = f[0][1] = f[0][0];
    f[0][0] = v;
  }
  else {
    matrix_exponent(n / 2);
    ll v1 = (f[0][0]*f[0][0] + f[0][1]*f[1][0]) % mod;
    ll v2 = (f[0][0]*f[0][1] + f[0][1]*f[1][1]) % mod;
    ll v3 = (f[1][0]*f[0][0] + f[1][1]*f[1][0]) % mod;
    ll v4 = (f[1][0]*f[0][1] + f[1][1]*f[1][1]) % mod;
    f[0][0] = v1, f[0][1] = v2, f[1][0] = v3, f[1][1] = v4;
  }
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    ll n, x, m, y, k;
    cin >> n >> x >> m >> y >> k;
    ll mx = max(n, m), ct = 0;
    vector <ll> fibo = {0, 1};
    for(int i = 2; ;i++) {
      fibo.push_back(fibo[i-1] + fibo[i-2]);
      if(fibo[i] >= mod) {
        ct = i;
        break;
      }
    }

    cout << "Case " << cs++ << ": ";
    if(n >= ct or m >= ct) {
      cout << "Impossible" << endl;
      continue;
    }

    ll a1 = fibo[n], b1 = fibo[n+1];
    ll a2 = fibo[m], b2 = fibo[m+1];
    ll nux = (x*b2 - y*b1), dex = (a1*b2 - a2*b1);
    ll nuy = (x*a2 - y*a1), dey = (a2*b1 - a1*b2);
    if(dex == 0 || (nux%dex) != 0 || (nux/dex) < 0 || (nuy%dey) != 0 || (nuy/dey) < 0) {
      cout << "Impossible" << endl;
      continue;
    }

    ll xx = nux / dex, yy = nuy / dey;

    f[0][0] = f[0][1] = f[1][0] = 1, f[1][1] = 0;
    matrix_exponent(k);
    ll aa = f[0][1], bb = f[0][0];

    ll ans = ((aa*xx) + (bb*yy)) % mod;
    cout << ans << endl;
  }
}
