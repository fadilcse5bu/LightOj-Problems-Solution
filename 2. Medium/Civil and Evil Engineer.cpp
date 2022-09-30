#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair <ll, ll> pr;

vector <pair<ll, ll>> edges[200005];
bool taken_node[200005];

int main()
{
  ll tc = 1, cs = 1; //test case
  cin >> tc;
  while(tc--) {
    ll n;
    cin >> n;
    for(int i = 0; i <= n; i++) {
      edges[i].clear();
      taken_node[i] = false;
    }
    while(1) {
      ll u, v, w;
      cin >> u >> v >> w;
      if(u == 0 && v == 0) break;
      edges[u].push_back({v, w});
      edges[v].push_back({u, w});
    }

    priority_queue <pr, vector<pr>, greater<pr>> min_pq; // increasing order
    priority_queue <pr> max_pq;
    for(int i = 0; i < edges[0].size(); i++) {
      min_pq.push({edges[0][i].second, edges[0][i].first});
      max_pq.push({edges[0][i].second, edges[0][i].first});
    }

    ll min_cost = 0;
    taken_node[0] = true;
    while(!min_pq.empty()) {
      ll u = min_pq.top().first, v = min_pq.top().second;
      min_pq.pop();
      if(taken_node[v] == true) continue;
      taken_node[v] = true;
      min_cost += u;
      for(int i = 0; i < edges[v].size(); i++) {
          min_pq.push({edges[v][i].second, edges[v][i].first});
      }
    }

    ll max_cost = 0;
    for(int i = 0; i <= n; i++) taken_node[i] = false;
    taken_node[0] = true;
    while(!max_pq.empty()) {
      ll u = max_pq.top().first, v = max_pq.top().second;
      max_pq.pop();
      if(taken_node[v] == true) continue;
      taken_node[v] = true;
      max_cost += u;
      for(int i = 0; i < edges[v].size(); i++) {
          max_pq.push({edges[v][i].second, edges[v][i].first});
      }
    }

    ll ans = min_cost + max_cost;
    cout << "Case " << cs++ << ": ";
    if(ans % 2 == 0) cout << ans / 2;
    else cout << ans << '/' << 2;
    cout << endl;
  }

	return 0;
}


