/// How many number of integers in the range [A, B] which are divisible by K and the sum of its digits is also divisible by K.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[55][85][85][2][2], k;
int len = 55;
string a, b; // fa = flag of lower number(a), fb = flag of upper number(b)

ll cal(int pos, int mod1, int mod2, bool fa, bool fb) {
  if(pos == len) return (mod1==0 && mod2==0);
  ll &ret = dp[pos][mod1][mod2][fa][fb];
  if(ret != -1 && fa && fb) return ret;
  ret = 0;
  int low = fa? 0:a[pos]-'0';
  int high = fb? 9:b[pos]-'0';
  for(int i = low; i <= high; i++) {
    ret += cal(pos+1, (mod1*10+i)%k, (mod2+i)%k, fa|(i>low), fb|(i<high));
  }
  return ret;
}

void process() {
  memset(dp, -1, sizeof dp);
  int la = a.size(), lb = b.size();
  string sa = "", sb = "";
  for(int i = la; i < len; i++) sa += '0';
  for(int i = lb; i < len; i++) sb += '0';
  a = sa + a;
  b = sb + b;
}

int main()
{
  int t=1, cs=1; cin >> t;
  //memset(dp, -1, sizeof dp);
  while(t--) {
    cin >> a >> b >> k;
    cout << "Case " << cs++ << ": ";
    if(k > 81) {
      cout << 0 << endl;
      continue;
    }
    process();
    ll ans = cal(0,0,0,0,0);
    cout << ans << endl;
  }

  return 0;
}
/*
3
1 20 1
1 20 2
1 1000 4

Case 1: 20
Case 2: 5
Case 3: 64
*/





