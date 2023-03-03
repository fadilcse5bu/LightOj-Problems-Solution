#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

//ll mod = 9223372036854775807;
int const ln = 2;
ll base[ln][ln] = {{0,0},{1,0}};

void multiply(ll a[ln][ln], ll b[ln][ln]) {
  ll temp[ln][ln];
  for(int i = 0; i < ln; i++) {
    for(int j = 0; j < ln; j++) {
      temp[i][j] = 0;
      for(int k = 0; k < ln; k++) {
        temp[i][j] += (a[i][k]*b[k][j]);
      }
    }
  }
  for(int i = 0; i < ln; i++) {
    for(int j = 0; j < ln; j++) {
      a[i][j] = temp[i][j];
    }
  }
}

void power(int n, ll mat[ln][ln]) {
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
    unsigned long long p, q, n;
    cin >> p >> q >> n;
    cout << "Case " << cs++ << ": ";
    if(n == 0) {
      cout << 2 << endl;
      continue;
    }
    if(n == 1) {
      cout << p << endl;
      continue;
    }

    base[0][0] = p, base[0][1] = -q;
    ll mat[ln][ln] = {{p,-q},{1,0}};

    power(n-1, mat);
    ll fn = (mat[0][0]*p + mat[0][1]*2);
    cout << fn << endl;
  }

  return 0;
}
