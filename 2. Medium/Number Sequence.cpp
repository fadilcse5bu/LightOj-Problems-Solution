#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod;
ll f[2][2], base[2][2];

void matrix_exponent(ll n) {
  if(n <= 1) return;
  if(n%2 == 1) {
    matrix_exponent(n-1);
    ll v1 = (f[0][0]*base[0][0] + f[0][1]*base[1][0]) % mod;
    ll v2 = (f[0][0]*base[0][1] + f[0][1]*base[1][1]) % mod;
    ll v3 = (f[1][0]*base[0][0] + f[1][1]*base[1][0]) % mod;
    ll v4 = (f[1][0]*base[0][1] + f[1][1]*base[1][1]) % mod;
    f[0][0] = v1, f[0][1] = v2, f[1][0] = v3, f[1][1] = v4;
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
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    mod = 1;
    for(int i = 1; i <= m; i++) mod *= 10;

    f[0][0] = base[0][0] = 1;
    f[0][1] = base[0][1] = 1;
    f[1][0] = base[1][0] = 1;
    f[1][1] = base[1][1] = 0;

    ll fn;
    if(n == 0) fn = a;
    else if(n == 1) fn = b;
    else {
      matrix_exponent(n-1);
      fn = (f[0][0]*b + f[0][1]*a) % mod;
    }

    cout << "Case " << cs++ << ": " << fn << endl;
  }
}

