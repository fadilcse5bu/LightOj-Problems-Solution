#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);

int main()
{
  int t, tc = 1;
  cin >> t;
  while(t--) {
    double R, n;
    cin >> R >> n;
    double r = R * sin(pi / n) / (1 + sin(pi/n));
    cout << "Case " << tc++ << ": ";
    printf("%.10lf\n", r);
  }

  return 0;
}
