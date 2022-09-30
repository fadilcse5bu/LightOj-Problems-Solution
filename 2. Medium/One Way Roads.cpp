#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    map <pair<int,int>, int> mp;
    vector <int> ve[n+1];
    for(int i = 1; i <= n; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      mp[{u, v}] = c;
      ve[u].push_back(v);
      ve[v].push_back(u);
    }

    int a = 1, b = ve[1][0], s = 0;
    if(mp[{a, b}] == 0) s += mp[{b, a}];
    while(b != 1) {
      int c = a;
      a = b;
      if(ve[b][0] != c) b = ve[b][0];
      else b = ve[b][1];
      if(mp[{a, b}] == 0) s += mp[{b, a}];
    }

    int ans = s;
    a = 1, b = ve[1][1], s = 0;
    if(mp[{a, b}] == 0) s += mp[{b, a}];
    while(b != 1) {
      int c = a;
      a = b;
      if(ve[b][0] != c) b = ve[b][0];
      else b = ve[b][1];
      if(mp[{a, b}] == 0) s += mp[{b, a}];
    }

    ans = min(ans, s);
    cout << "Case " << cs++ << ": " << ans << endl;
  }

	return 0;
}

