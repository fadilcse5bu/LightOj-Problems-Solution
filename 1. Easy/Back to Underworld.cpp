#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int col[20005], ck[20005], o, z;
vector <int> ve[20005];

void Set() {
  for(int i = 0; i <= 20000; i++) {
    ve[i].clear();
    col[i] = -1;
    ck[i] = 0;
  }
}

void dfs(int x) {
  col[x] = 1;
  for(int i = 0; i < ve[x].size(); i++) {
    if(col[ve[x][i]] == 0) {
      if(ck[x] == 0) {
        ck[ve[x][i]] = 1;
        ++o;
      }
      else ++z;
      dfs(ve[x][i]);
    }
  }
}

int main()
{
  ll t, tc = 1;
  cin >> t;
  start:
  while(t--) {
    Set();
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;
      ve[u].push_back(v);
      ve[v].push_back(u);
      col[u] = 0, col[v] = 0;
    }

    for(int i = 1; i <= 20000; i++) {
      if(col[i] == 0) {
        o = 0, z = 1;
        dfs(i);
        ans += max(o, z);
      }
    }

    cout << "Case " << tc << ": ";
    cout << ans << endl;
    ++tc;
  }

	return 0;
}
