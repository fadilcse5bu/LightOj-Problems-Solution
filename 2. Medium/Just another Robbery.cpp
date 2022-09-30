#include <bits/stdc++.h>
using namespace std;

int m[105], n;
double p[105], dp[105][10005];
bool vis[105][10005];

double cal(int pos, int money) {
  if(pos > n) {
    if(money == 0) return 1;
    else return 0;
  }
  if(vis[pos][money]) return dp[pos][money];

  vis[pos][money] = 1;
  double ret = cal(pos+1, money);
  if(money - m[pos] >= 0) {
    ret = max(ret, (1.0 - p[pos])*cal(pos+1, money-m[pos]));
  }
  return dp[pos][money] = ret;
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    memset(vis, 0, sizeof(vis));
    memset(dp, 0.0, sizeof(dp));
    double P;
    int total = 0;
    cin >> P >> n;
    for(int i = 1; i <= n; i++) {
      cin >> m[i] >> p[i];
      total += m[i];
    }

    int maxMoney = 0;
    for(int i = 1; i <= total; i++) {
      if(1.0 - cal(1, i) < P) maxMoney = i;
    }

    cout << "Case " << cs++ << ": " << maxMoney << endl;
  }
}
