#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int n, w, k;
    cin >> n >> w >> k;
    vector <int> a(n+1), pre(n+1), pos(n+1), mx(n+1, 0), dp(n+1);
    for(int i = 0; i < n; i++) {
      int x, y; cin >> x >> y;
      a[i] = y;
    }
    a[n] = INT_MIN / 2;
    sort(a.begin(), a.end());

    for(int i = 1; i <= n; i++) {
      int p = upper_bound(a.begin(), a.end(), a[i]+w) - a.begin();
      pos[i] = p - i;
      p = lower_bound(a.begin(), a.end(), a[i]-w) - a.begin();
      pre[i] = p - 1;
    }

    int ans = 0;
    while(k--) {
      for(int i = 1; i <= n; i++) {
        dp[i] = pos[i] + mx[pre[i]];
        ans = max(ans, dp[i]);
      }
      for(int i = 1; i <= n; i++) {
        mx[i] = max(mx[i-1], dp[i]);
      }
    }

    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
