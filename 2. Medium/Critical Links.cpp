#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector <int> edges[10005];
vector <pair<int, int>> bridge;
int tme, low[10005], disc[10005], par[10005];
bool visit[10005];

void dfs(int x, int p) {
  par[x] = p;
  visit[x] = 1;
  low[x] = disc[x] = ++tme;
  for(int i = 0; i < edges[x].size(); i++) {
    if(!visit[edges[x][i]]) {
      dfs(edges[x][i], x);
      low[x] = min(low[x], low[edges[x][i]]);
      if(low[edges[x][i]] > disc[x]) {
        if(edges[x][i] > x) {
          bridge.push_back({x, edges[x][i]});
        }
        else {
          bridge.push_back({edges[x][i], x});
        }
      }
    }
    else if(edges[x][i] != par[x]) {
      low[x] = min(low[x], disc[edges[x][i]]);
    }
  }
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    bridge.clear();
    for(int i = 0; i < n; i++) {
      visit[i] = 0;
      edges[i].clear();
    }
    for(int i = 0; i < n; i++) {
      int u, e, v, nd;
      cin >> u;
      char c1, c2;
      cin >> c1 >> nd >> c2;
      while(nd--) {
        cin >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
      }
    }

    for(int i = 0; i < n; i++) {
      if(visit[i] == 0) {
        dfs(i, -1);
      }
    }

    sort(bridge.begin(), bridge.end());

    cout << "Case " << cs++ << ":" << endl;
    cout << bridge.size() << " critical links" << endl;
    for(int i = 0; i < bridge.size(); i++) {
      cout << bridge[i].first << " - " << bridge[i].second << endl;
    }
  }


	return 0;
}

