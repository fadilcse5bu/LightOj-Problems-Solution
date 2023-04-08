#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int const N = 1000005;
int pr[N][2];

int main()
{
  for(int i = 2; i < N; i++) {
    int v = i, ct = 0;
    while(v%2==0) {
      v /= 2;
      ct++;
    }
    pr[i][0] = pr[i-1][0] + ct;
    ct = 0;
    while(v%5==0) {
      v /= 5;
      ct++;
    }
    pr[i][1] = pr[i-1][1] + ct;
  }

  int t = 1, cs = 1;
  scanf("%d", &t);
  while(t--) {
    int n, r, p, q;
    scanf("%d%d%d%d",&n,&r,&p,&q);
    int ct2 = 0, ct5 = 0;
    while(p%2==0) {
      p /= 2;
      ct2++;
    }
    while(p%5==0) {
      p /= 5;
      ct5++;
    }
    ct2 *= q;
    ct5 *= q;
    int p2 = pr[n][0] - pr[r][0] - pr[n-r][0] + ct2;
    int p5 = pr[n][1] - pr[r][1] - pr[n-r][1] + ct5;
    int ans = min(p2, p5);
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}
