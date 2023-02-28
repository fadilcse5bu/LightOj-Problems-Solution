#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

ll dp[50][50][2][2][2], k;
int len = 50;
string a, b; // fa = flag of lower number(a), fb = flag of upper number(b)

ll cal(int pos, int cnt, bool pre, bool fa, bool fb) {
  if(pos == len) return cnt;
  ll &ret = dp[pos][cnt][pre][fa][fb];
  if(ret != -1) return ret;
  ret = 0;
  int low = fa? 0:a[pos]-'0';
  int high = fb? 1:b[pos]-'0';
  for(int i = low; i <= high; i++) {
    int v = cnt;
    if(pre == 1 && i == 1) ++v;
    ret = (ret + cal(pos+1, v, i, fa|(i>low), fb|(i<high)));
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
  while(t--) {
    a.clear(); b.clear();
    int n; cin >> n;
    while(n>0) {
      if(n%2) b.push_back('1');
      else b.push_back('0');
      n /= 2;
    }
    reverse(b.begin(), b.end());
    process();
    ll ans = cal(0,0,0,0,0);
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
/*
7
0
6
15
20
21
22
2147483647


Case 1: 0
Case 2: 2
Case 3: 12
Case 4: 13
Case 5: 13
Case 6: 14
Case 7: 16106127360

*/





