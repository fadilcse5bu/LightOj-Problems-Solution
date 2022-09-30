#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair <ll, ll> pr;

vector <pair<ll, ll>> edges[200005];
bool taken_node[200005];

int main()
{
  ll tc, cs = 1; //test case
  cin >> tc;
  start:
  while(tc--) {
    ll n = 0, e; //number of node && number of edges
    cin >> e;
    for(int i = 1; i <= 200; i++) edges[i].clear();
    map <string, int> mp;
    for(int i = 1; i <= e; i++) {
      string st, st1;
      ll u, v, w;
      cin >> st >> st1 >> w;
      if(mp[st] == 0) mp[st] = ++n;
      if(mp[st1] == 0) mp[st1] = ++n;
      u = mp[st], v = mp[st1];
      edges[u].push_back({v, w});
      edges[v].push_back({u, w});
    }

    priority_queue <pr, vector<pr>, greater<pr>> pq; // increasing order
    for(int i = 0; i < edges[1].size(); i++) {
      pq.push({edges[1][i].second, edges[1][i].first});
    }

    ll min_cost = 0;
    memset(taken_node, false, sizeof taken_node);
    taken_node[1] = true;
    while(!pq.empty()) {
      ll u = pq.top().first, v = pq.top().second;
      pq.pop();
      if(taken_node[v] == true) continue;
      taken_node[v] = true;
      min_cost += u;
      for(int i = 0; i < edges[v].size(); i++) {
          pq.push({edges[v][i].second, edges[v][i].first});
      }
    }

    cout << "Case " << cs++ << ": ";
    for(int i = 1; i <= n; i++) {
      if(taken_node[i] == false) {
        cout << "Impossible" << endl;
        goto start;
      }
    }
    cout << min_cost << endl;
  }

	return 0;
}


