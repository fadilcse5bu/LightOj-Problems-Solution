#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod, a1, b1, c1, a2, b2, c2;
ll base[6][6] = {{-1,-1,0,0,0,-1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,-1,-1,-1,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};

void multiply(ll a[6][6], ll b[6][6]) {
  ll temp[6][6];
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 6; j++) {
      temp[i][j] = 0;
      for(int k = 0; k < 6; k++) {
        temp[i][j] += (a[i][k]*b[k][j])%mod;
      }
    }
  }
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 6; j++) {
      a[i][j] = temp[i][j];
    }
  }
}

void power(int n, ll mat[6][6]) {
  if(n == 1) return;
  power(n/2, mat);
  multiply(mat, mat);
  if(n&1) multiply(mat, base);
}

// f(n) = a1*f(n-1) + b1*f(n-2) + c1*g(n-3);
// g(n) = a2*g(n-1) + b2*g(n-2) + c2*f(n-3);
int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    ll f[3], g[3];
    cin >> f[0] >> f[1] >> f[2];
    cin >> g[0] >> g[1] >> g[2];
    cin >> mod;

    base[0][0] = a1, base[0][1] = b1, base[0][5] = c1;
    base[3][2] = c2, base[3][3] = a2, base[3][4] = b2;

    cout << "Case " << cs++ << ":" << endl;
    int q; cin >> q;
    while(q--) {
      int n; cin >> n;
      if(n <= 2) {
        cout << f[n]%mod << ' ' << g[n]%mod << endl;
        continue;
      }
      ll mat[6][6];
      for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
          mat[i][j] = base[i][j];
        }
      }
      power(n-2, mat);
      ll fn = (mat[0][0]*f[2]+mat[0][1]*f[1]+mat[0][2]*f[0]+mat[0][3]*g[2]+mat[0][4]*g[1]+mat[0][5]*g[0])%mod;
      ll gn = (mat[3][0]*f[2]+mat[3][1]*f[1]+mat[3][2]*f[0]+mat[3][3]*g[2]+mat[3][4]*g[1]+mat[3][5]*g[0])%mod;
      cout << fn << ' ' << gn << endl;
    }
  }

  return 0;
}
