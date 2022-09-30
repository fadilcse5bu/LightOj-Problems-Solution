#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t, tc = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    double ar[n], ev[n];
    for(int i = 0; i < n; i++) cin >> ar[i];
    for(int i = n - 1; i >= 0; i--) {
      ev[i] = ar[i];
      int ct = 0;
      double v = 0;
      for(int j = i + 1; j < n && ct < 6; j++, ct++) {
        v += ev[j];
      }
      if(ct > 0) {
        v /= (ct * 1.0);
      }
      ev[i] += v;
    }
    cout << "Case " << tc++ << ": ";
    printf("%.10lf\n", ev[0]);
  }

  return 0;
}
