#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    ll ar[n], high = 5, low = 0;
    for(int i = 0; i < n; i++) {
      cin >> ar[i];
      low = max(low, ar[i]);
      high += ar[i];
    }
    while(low < high) {
      ll mid = (low+high)/2, ct = 1, s = 0;
      for(int i = 0; i < n; i++) {
        s += ar[i];
        if(s > mid) {
          s = ar[i];
          ct++;
        }
      }
      if(ct > m) {
        low = mid+1;
      }
      else {
        high = mid;
      }
    }
    cout << "Case " << cs++ << ": " << high << endl;
  }

  return 0;
}
