#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[505][505];
ll mod = 1e9+7;
const int N = 10005;
vector <ll> p;
bool ck[N];

void sieve() {
  p.push_back(1);
  p.push_back(2);
  for(ll i = 3; i < N; i += 2) {
    if(ck[i] == 1) continue;
    p.push_back(i);
    for(ll j = i*i; j < N; j += (2*i)) {
      ck[j] = 1;
    }
  }
}

void cal() {
  dp[1][1] = 1;
  for(int i = 2; i <= 500; i++) {
    dp[1][i] = (dp[1][i-1]*2)%mod;
  }
  for(int i = 2; i <= 500; i++) {
    for(int j = i; j <= 500; j++) {
      dp[i][j] = ((dp[i-1][j-1]*(p[i]-1)) + dp[i][j-1]*p[i])%mod;
    }
  }
}

int main()
{
  sieve();
  cal();
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int K, P; cin >> K >> P;
    cout << "Case " << cs++ << ": " << dp[P][K] << endl;
  }

  return 0;
}
