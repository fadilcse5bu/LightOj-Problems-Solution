#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    double x, y, c;
    cin >> x >> y >> c;
    double low = 0, high = min(x, y);

    int ct = 100;
    while(ct--) {
      double mid = (low + high) / 2.0;
      double h2 = sqrt((x*x) - (mid*mid)), h1 = sqrt((y*y) - (mid*mid));
      double h = (h1*h2) / (h1+h2);
      if(h >= c) low = mid;
      else high = mid;
    }

    cout << "Case " << cs++ << ": " << fixed << setprecision(10) << low << endl;
  }

  return 0;
}
