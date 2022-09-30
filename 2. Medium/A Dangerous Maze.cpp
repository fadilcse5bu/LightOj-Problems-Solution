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
    ll x, evd = 0, evn = 0;
    for(int i = 0; i < n; i++) {
      cin >> x;
      if(x < 0) {
        evd += (x * -1);
        ++evn;
      }
      else evd += x;
    }
    evn = n - evn;

    cout << "Case " << tc++ << ": ";
    if(evn == 0) {
      cout << "inf" << endl;
    }
    else {
      ll gcd =  __gcd(evd, evn);
      evd /= gcd;
      evn /= gcd;
      cout << evd << "/" << evn << endl;
    }
  }

  return 0;
}
