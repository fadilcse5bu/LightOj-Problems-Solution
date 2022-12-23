#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int convertDigit(char ch) {
  if(ch >= '0' && ch <= '9') return ch - '0';
  else return ch - 'A' + 10;
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int base, k; cin >> base >> k;
    string num; cin >> num;
    int len = num.size();
    int dp[(1<<len)][21];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int mask = 0; mask < (1<<len); mask++) {
      for(int indx = 0; indx < len; indx++) {
        if(mask & (1<<indx)) continue;
        for(int rem = 0; rem < k; rem++) {
          int digit = convertDigit(num[indx]);
          dp[mask | (1<<indx)][(rem*base+digit)%k] += dp[mask][rem];
        }
      }
    }
    cout << "Case " << cs++ << ": " << dp[(1<<len)-1][0] << endl;
  }

  return 0;
}
