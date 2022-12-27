#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    char ch;
    double a, b; cin >> a >> ch >> b;

    double radius = sqrt(a*a+b*b)/2.0;
    double theta = 2.0*atan(b/a);
    double s = radius*theta;
    double x = 400.0/(2*s + 2*a);

    cout << "Case " << cs++ << ": ";
    cout << setprecision(10);
    cout << fixed << x*a << ' ' << x*b << endl;
  }

  return 0;
}
