#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dis[105], inf = INT_MAX, n, m, u, v, w;
vector <pair<int, int>> G[105];

void Dijkstra(int s) {
  priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int v = p.second;
    for(int i = 0; i < G[v].size(); i++) {
      if(dis[v] + G[v][i].second < dis[G[v][i].first]) {
        dis[G[v][i].first] = dis[v] + G[v][i].second;
        pq.push({dis[G[v][i].first], G[v][i].first});
      }
    }
  }
}

int main() {
  int t, cs = 1;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
      dis[i] = INT_MAX;
      G[i].clear();
    }
    dis[1] = 0;

    for(int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      G[u].push_back({v, w});
      G[v].push_back({u, w});
    }
    Dijkstra(1);
    if(dis[n] == INT_MAX) {
      cout << "Case " << cs++ << ": " << "Impossible" << endl;
    }
    else {
      cout << "Case " << cs++ << ": " << dis[n] << endl;
    }
  }
}



