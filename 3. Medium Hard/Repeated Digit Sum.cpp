#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    string a, b; cin >> a >> b;
    cout << "Case " << cs++ << ": ";
    ll x = 0, y = 0;
    for(int i = 0; i < a.size(); i++) {
      x = (x*10 + a[i]-'0')%9;
    }
    for(int i = 0; i < b.size(); i++) {
      y = (y*10 + b[i]-'0')%6;
    }
    y += 6;
    if(b.size()==1) {
      if(b[0] == '0' or b[0] == '1') y = b[0]-'0';
    }
    ll ans = 1;
    while(y--) {
      ans = (ans*x)%9;
    }
    if(a != "0" && !ans) ans = 9;
    cout << ans << endl;
  }

	return 0;
}

