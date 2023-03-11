#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll n; cin >> n;
    ll ar[n];
    for(int i = 0; i < n; i++) {
      cin >> ar[i];
    }
    sort(ar, ar + n);
    ll ans = 0;
    for(ll i = 0; i < n - 2; i++) {
      for(ll j = i + 1; j < n - 1; j++) {
        ll s = ar[i] + ar[j];
        ll low = j, high = n-1;
        while(low <= high) {
          ll mid = (low+high)/2;
          if(ar[mid] >= s) {
            high = mid-1;
          }
          else low = mid+1;
        }
        ans += (high - j);
      }
    }
    cout << "Case " << cs++ << ": ";
    cout << ans << endl;
  }

  return 0;
}
