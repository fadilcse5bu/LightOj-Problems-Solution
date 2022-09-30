#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair <int, int> pd;

bool vis[54], taken[55];
vector <int> edges[55];
void dfs(int x) {
  vis[x] = true;
  for(int i = 0; i < edges[x].size(); i++) {
    if(vis[edges[x][i]] == false) dfs(edges[x][i]);
  }
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int n, tl = 0;
    cin >> n;
    int cables[n+1][n+1];
    for(int i = 1; i <= n; i++) {
      edges[i].clear();
      for(int j = 1; j <= n; j++) {
        cin >> cables[i][j];
        tl += cables[i][j];
      }
    }
    memset(vis, false, sizeof vis);
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(i == j) {
          continue;
        }
        if(cables[i][j] > 0 && cables[j][i] > 0) {
          cables[i][j] = min(cables[i][j], cables[j][i]);
          cables[j][i] = min(cables[i][j], cables[j][i]);
        }
      }
    }

    vector <pair<int,int> > ve[n + 1];
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(i == j) continue;
        if(cables[i][j] > 0) {
          edges[i].push_back(j);
          edges[j].push_back(i);
          ve[i].push_back({j, cables[i][j]});
          ve[j].push_back({i, cables[i][j]});
        }
      }
    }

    priority_queue <pd, vector<pd>, greater<pd> > pq;
    for(int i = 0; i < ve[1].size(); i++) {
      pq.push(make_pair(ve[1][i].second, ve[1][i].first));
    }

    memset(taken, false, sizeof taken);
    taken[1] = true;
    int mst = 0;
    while(!pq.empty()) {
      int u = pq.top().first, v = pq.top().second;
      pq.pop();
      if(taken[v] == true) continue;
      taken[v] = true;
      mst += u;
      for(int i = 0; i < ve[v].size(); i++) {
          pq.push({ve[v][i].second, ve[v][i].first});
      }
    }

    int ans = tl - mst;

    dfs(1);
    for(int i = 1; i <= n; i++) {
      if(vis[i] == false) {
        ans = -1;
        break;
      }
    }

    cout << "Case " << cs++ << ": " << ans << endl;
  }

	return 0;
}

