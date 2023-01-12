#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <ll> g[100005];
ll cntAncestor[100005], cntSuccessor[100005];
bool vis[100005];

void dfs(ll x) {
  vis[x] = true;
  for(int i = 0; i < g[x].size(); i++) {
    if(!vis[g[x][i]]) {
      cntAncestor[g[x][i]] = cntAncestor[x] + 1;
      dfs(g[x][i]);
    }
  }
  for(int i = 0; i < g[x].size(); i++) {
    cntSuccessor[x] += cntSuccessor[g[x][i]];
  }
}

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    for(int i = 0; i <= n; i++) {
      g[i].clear();
      cntAncestor[i] = 0;
      cntSuccessor[i] = 1;
      vis[i] = false;
    }
    for(int i = 1; i < n; i++) {
      ll x, y; cin >> x >> y;
      g[x].push_back(y);
    }
    dfs(1);

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
      ans += (n - cntAncestor[i] - cntSuccessor[i]);
    }
    cout << "Case " << cs++ << ": " << n-1 <<  ' ' << ans/2 << endl;
  }

  return 0;
}
