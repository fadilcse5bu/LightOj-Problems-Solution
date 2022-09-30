#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t;
  cin >> t;
  start:
  for(int tc = 1; tc <= t; tc++) {
    int n, w;
    cin >> n >> w;
    ll ar[n];
    for(int i = 0; i < n; i++) {
      ll x;
      cin >> x >> ar[i];
    }

    sort(ar, ar + n);
    ll r = ar[0], ans = 1;
    for(int i = 1; i < n; i++) {
      if(ar[i] > r + w) {
        ++ans;
        r = ar[i];
      }
    }

    cout << "Case " << tc << ": " << ans << endl;
  }

	return 0;
}
