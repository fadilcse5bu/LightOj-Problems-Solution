#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    int n, ck = 0; cin >> n;
    map <int, int> mp;
    for(int i = 0; i < n; i++) {
      int a; cin >> a;
      if(a >= n) {
        ck = -1;
        continue;
      }
      if(mp[a] == 0) mp[a] = 1;
      else {
        int v = n - a - 1;
        if(mp[v] == 1) ck = -1;
        else mp[v] = 1;
      }
    }
    cout << "Case " << cs++ << ": ";
    if(ck == -1) cout << "no" << endl;
    else cout << "yes" << endl;
  }

  return 0;
}
