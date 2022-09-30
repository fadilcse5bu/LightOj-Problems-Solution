#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t, ca = 1;
  cin >> t;
  while(ca <= t) {
    int n, m;
    cin >> n >> m;
    vector <int> vp[n + 1];
    int ad[n + 1][n + 1];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        ad[i][j] = -1;
      }
    }

    for(int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      if(ad[u][v] == -1) {
        vp[u].push_back(v);
        vp[v].push_back(u);
        ad[u][v] = c;
        ad[v][u] = c;
      }
      else {
        if(ad[u][v] > c) {
          ad[u][v] = c;
          ad[v][u] = c;
        }
      }
    }

    int tar;
    cin >> tar;

    int cost[505];
    for(int i = 0; i <= 500; i++) {
        cost[i] = 200000;
    }

    priority_queue <pair<int ,int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < vp[tar].size(); i++) {
      int in = vp[tar][i];
      pq.push({ad[vp[tar][i]][tar], vp[tar][i]});
      cost[vp[tar][i]] = ad[vp[tar][i]][tar];
    }

    cost[tar] = 0;
    while(!pq.empty()) {
      int v = pq.top().first;
      int node = pq.top().second;

      pq.pop();
      for(int i = 0; i < vp[node].size(); i++) {
        int v = max(ad[vp[node][i]][node], cost[node]);
        if(v < cost[vp[node][i]]) {
          cost[vp[node][i]] = v;
          pq.push({v, vp[node][i]});
        }
      }
    }


    cout << "Case " << ca << ":" << endl;
    ++ca;
    for(int i = 0; i < n; i++) {
      if(cost[i] == 200000) cout << "Impossible" << endl;
      else cout << cost[i] << endl;
    }
  }

	return 0;
}
