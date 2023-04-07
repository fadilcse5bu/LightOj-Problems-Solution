#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t = 1, cs = 1;
  scanf("%d", &t);
  while(t--) {
    ll ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    ll dx = abs(ax-bx), dy = abs(ay-by);
    ll ans = 1 + __gcd(dx, dy);
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
