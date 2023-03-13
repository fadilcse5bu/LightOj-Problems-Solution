#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    int n; cin >> n;
    int ar[n+1];
    for(int i = 1; i <= n; i++) cin >> ar[i];
    bool vis[n+1] = {0};
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      int ct = 0, in = i;
      while(vis[in] == 0) {
        vis[in] = 1;
        ++ct;
        in = ar[in];
      }
      if(ct == 0) ct = 1;
      ans += ct - 1;
    }
    cout << "Case " << cs++ << ": " << ans << endl;
  }

	return 0;
}

