#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    string mb, me;
    ll db, de, yb, ye;
    char coma;
    cin >> mb >> db >> coma >> yb;
    cin >> me >> de >> coma >> ye;

    bool ck = false;
    if(yb%400 == 0 || (yb%100 != 0 && yb%4 == 0)) {
      if(mb == "January") ck = true;
      else if(mb == "February" && db <= 29) ck = true;
    }
    while(!ck) {
      ++yb;
      if(yb%400 == 0 || (yb%100 != 0 && yb%4 == 0)) {
        ck = true;
      }
    }

    ck = false;
    if(ye%400 == 0 || (ye%100 != 0 && ye%4 == 0)) {
      if(me == "February") {
        if(de >= 29) ck = true;
      }
      else if(me != "January") ck = true;
    }
    while(!ck) {
      --ye;
      if(ye%400 == 0 || (ye%100 != 0 && ye%4 == 0)) {
        ck = true;
      }
    }
    ll ans = (ye/4 - (yb-1)/4) - (ye/100 - (yb-1)/100) + (ye/400 - (yb-1)/400);
    if(yb > ye) ans = 0;
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
