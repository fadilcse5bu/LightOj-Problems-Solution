#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n, m, d, q, ar[405];
unsigned long dp[405][45][25];

ll cal(ll pos, ll mod, ll cnt) {
  if(cnt == m) {
    if(!mod) return 1;
    return 0;
  }
  if(pos == n) return 0;
  if(dp[pos][mod][cnt] != -1) return dp[pos][mod][cnt];
  ll res = cal(pos+1, (mod+ar[pos])%d, cnt+1);
  res += cal(pos+1, mod, cnt);
  return dp[pos][mod][cnt] = res;
}

int main () {
  ll t, cs = 1;
  cin >> t;
  while(t--) {
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> ar[i];
    cout << "Case " << cs++ << ":\n";
    while(q--) {
      cin >> d >> m;
      memset(dp, -1, sizeof(dp));
      cout << cal(0,0,0) << endl;
    }
  }
  return 0;
}
