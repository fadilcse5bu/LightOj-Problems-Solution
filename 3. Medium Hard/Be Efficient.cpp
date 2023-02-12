#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll n, m; cin >> n >> m;
    ll cnt[m+1] = {0}, ans = 0, sum = 0;
    cnt[0] = 1;
    for(int i = 0; i < n; i++) {
      ll a; cin >> a;
      sum = (sum + a) % m;
      ans += cnt[sum];
      cnt[sum]++;
    }
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
