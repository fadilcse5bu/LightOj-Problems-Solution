#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll n, m; cin >> m >> n;
    int S[m];
    ll cnt[n+1][10];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < m; i++) {
      cin >> S[i];
      cnt[0][S[i]] = 1;
    }

    for(int i = 1; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for(int k = max(0,S[j]-2); k <= min(S[j]+2, 9); k++) {
          cnt[i][S[j]] += cnt[i-1][k];
        }
      }
    }

    ll ans = 0;
    for(int i = 0; i < 10; i++) ans += cnt[n-1][i];

    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
