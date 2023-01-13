#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 10007;
ll base[4][4] = {{-1,0,-1,1},{1,0,0,0},{0,1,0,0},{0,0,0,1}};

void multiply(ll a[4][4], ll b[4][4]) {
  ll temp[4][4];
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      temp[i][j] = 0;
      for(int k = 0; k < 4; k++) {
        temp[i][j] += (a[i][k]*b[k][j])%mod;
      }
    }
  }
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      a[i][j] = temp[i][j];
    }
  }
}

void power(int n, ll mat[4][4]) {
  if(n == 1) return;
  power(n/2, mat);
  multiply(mat, mat);
  if(n&1) multiply(mat, base);
}

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << "Case " << cs++ << ": ";
    if(n <= 2) {
      cout << 0 << endl;
      continue;
    }

    base[0][0] = a, base[0][2] = b;
    ll mat[4][4] = {{a,0,b,1},{1,0,0,0},{0,1,0,0},{0,0,0,1}};

    power(n-2, mat);
    ll fn = (mat[0][3]*c) % mod;
    cout << fn << endl;
  }

  return 0;
}
