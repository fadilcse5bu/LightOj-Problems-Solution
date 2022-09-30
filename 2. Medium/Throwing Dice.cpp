#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[26][152], n, x;
ll cal(ll pos, ll sum) {
  if(pos > n) {
    if(sum == 0) return 1;
    else return 0;
  }
  if(dp[pos][sum] != -1) return dp[pos][sum];

  ll res = 0;
  for(ll i = 1; i <= 6; i++) {
    if(sum - i >= 0) {
      res += cal(pos+1, sum-i);
    }
  }

  return dp[pos][sum] = res;
}

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    cin >> n >> x;
    ll numerator = 0, denominator = pow(6, n);
    for(ll i = x; i <= n*6; i++) {
      memset(dp, -1, sizeof(dp));
      numerator += cal(1, i);
    }

    cout << "Case " << cs++ << ": ";
    if(numerator % denominator == 0) {
      cout << numerator / denominator << endl;
      continue;
    }

    ll gcd = __gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    cout << numerator << "/" << denominator << endl;
  }
}
