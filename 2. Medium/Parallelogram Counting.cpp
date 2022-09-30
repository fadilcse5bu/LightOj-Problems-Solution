#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <pair<int, int>> vp;

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int x[n], y[n];
    vp.clear();
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        int cx = (x[i] + x[j]), cy = (y[i] + y[j]);
        vp.push_back({cx, cy});
      }
    }
    sort(vp.begin(), vp.end());
    ll ct = 1, ans = 0;
    for(int i = 1; i < vp.size(); i++) {
      if(vp[i].first == vp[i-1].first && vp[i].second == vp[i-1].second) ++ct;
      else {
        ans += ((ct*(ct-1))/2);
        ct = 1;
      }
    }
    ans += ((ct*(ct-1))/2);

    cout << "Case " << cs++ << ": " << ans << endl;
  }
}
