#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll ar[35], W;
vector <ll> setV[2];

void buildArray(ll indx, ll n, ll sum, ll id) {
  if(sum > W) return;
  if(indx > n) {
    setV[id].push_back(sum);
    return;
  }
  buildArray(indx+1, n, sum, id);
  buildArray(indx+1, n, sum+ar[indx], id);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll n; cin >> n >> W;
    for(int i = 0; i < n; i++) cin >> ar[i];
    setV[0].clear(), setV[1].clear();
    buildArray(0, n/2-1, 0, 0);
    buildArray(n/2, n-1, 0, 1);
    sort(setV[1].begin(), setV[1].end());
    ll ans = 0;
    for(int i = 0; i < setV[0].size(); i++) {
      auto I = upper_bound(setV[1].begin(), setV[1].end(), W-setV[0][i]) - setV[1].begin();
      ans += I;
    }
    cout << "Case " << cs++ << ": " << ans << endl;
  }

  return 0;
}




