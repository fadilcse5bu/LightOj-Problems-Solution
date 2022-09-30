#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int spt[505][505][20]; //sparse table

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    int n, q, a;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        cin >> a;
        spt[i][j][0] = a;
      }
    }

    for(int k = 1; (1 << k) <= n; k++) {
      for(int i = 1; i + (1 << k) - 1 <= n; i++) {
        for(int j = 1; j + (1 << k) - 1 <= n; j++) {
          int a = 1<<(k-1);
          spt[i][j][k] = max(max(spt[i][j][k-1], spt[i+a][j][k-1]), max(spt[i][j+a][k-1], spt[i+a][j+a][k-1]));
        }
      }
    }

    cout << "Case " << cs++ << ":" << endl;
    while(q--) {
      int px, py, s;
      cin >> px >> py >> s;
      int qx = px+s-1, qy = py+s-1, k = log2(s);
      int a = (1<<k);
      int ans = max(max(spt[px][py][k], spt[qx-a+1][py][k]), max(spt[px][qy-a+1][k], spt[qx-a+1][qy-a+1][k]));

      cout << ans << endl;
    }
  }

  return 0;
}
