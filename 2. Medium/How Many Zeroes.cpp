/// Number of zeroes between A and B

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> num;
ll a, b;
ll dp[12][12][2][2];
ll call(ll pos, ll cnt, bool f, bool ck){
  if(pos == num.size()) return cnt;
  if(dp[pos][cnt][f][ck] != -1) return dp[pos][cnt][f][ck];
  ll high;
  if(f == 0) high = num[pos];
  else high = 9;
  ll res = 0;
  for(ll i = 0; i <= high; i++){
    ll v = 0;
    if(i == 0 && ck == 1) v = 1; // leaving leading zero
    res += call(pos+1, cnt + v, f|(i < high), ck|(i>0));
  }
  return dp[pos][cnt][f][ck] = res;
}

ll solve(ll b){
  num.clear();
  while(b>0){
    num.push_back(b%10);
    b/=10;
  }
  reverse(num.begin(), num.end());
  memset(dp, -1, sizeof(dp));
  ll res = call(0, 0, 0, 0);
  return res;
}

int main () {
  ll t, cs = 1;
  cin >> t;
  while(t--) {
    cin >> a >> b;
    ll res = solve(b);
    if(a == 0) res++;
    else res -= solve(a-1);
    cout << "Case " << cs++ << ": " << res << endl;
  }
  return 0;
}
