#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[10][2][85][85], len, k;

vector <int> dig;
void convertDigit(int n) {
  dig.clear();
  while(n > 0) {
    dig.push_back(n%10);
    n /= 10;
  }
  reverse(dig.begin(), dig.end());
  len = dig.size();
  //for(int i = 0; i < len; i++) cout << dig[i] << ' ';
  //cout << endl;
}

ll calculate(int pos, int tp, int mod1, int mod2) {
  if(pos == len) {
    if(mod1 == 0 && mod2 == 0) return 1;
    return 0;
  }
  if(dp[pos][tp][mod1][mod2] != -1) return dp[pos][tp][mod1][mod2];
  int lim;
  if(tp == 1) lim = 9;
  else lim = dig[pos];

  ll res = 0;
  for(int i = 0; i <= lim; i++) {
    res += calculate(pos+1, tp|(i < lim ? 1:0), (mod1*10+i)%k, (mod2+i)%k);
  }
  return dp[pos][tp][mod1][mod2] = res;
}

int main()
{
  int t=1, cs=1; cin >> t;
  while(t--) {
    int a, b; cin >> a >> b >> k;
    cout << "Case " << cs++ << ": ";
    if(k > 81) {
      cout << 0 << endl;
      continue;
    }
    memset(dp, -1, sizeof dp);
    convertDigit(b);
    int ans = calculate(0,0,0,0);
    memset(dp, -1, sizeof dp);
    convertDigit(a-1);
    ans -= calculate(0,0,0,0);
    cout << ans << endl;
  }

  return 0;
}


