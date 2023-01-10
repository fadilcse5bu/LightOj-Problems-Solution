#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

ll pool[50005][35], mod1 = 1e9 + 7, mod2 = 1e9+9, base1 = 61099, base2 = 595807;

int main()
{

  ll t = 1, cs = 1;
  cin >> t;
  while(t--) {
    ll l, k; cin >> l >> k;
    memset(pool, 0, sizeof pool);
    for(ll i = 1; i <= k; i++) {
      ll n; cin >> n;
      for(ll j = 1; j <= n; j++) {
        ll a; cin >> a;
        pool[++a][i]++;
      }
    }
    ll prefixMax[l+1] = {0};
    for(ll i = 1; i <= l; i++) {
      ll mx = 0;
      for(ll j = 1; j <= k; j++) {
        pool[i][j] += pool[i-1][j];
        mx = max(mx, pool[i][j]);
      }
      prefixMax[i] = mx;
    }

    vector <pair<ll,ll>>vp;
    for(int i = 0; i <= l; i++) {
      ll H1 = 1615102397;
      for(int j = 1; j <= k; j++) {
        H1 = ((H1*1615102397) ^ (prefixMax[i]-pool[i][j]));
      }
      //cout << i << ' ' << H1 << ' ' << endl;
      vp.push_back({H1,i});
    }

    ll indx = 0;
    sort(vp.begin(), vp.end());
    ll ans = 0;
    for(int i = 1; i < vp.size(); i++) {
      if(vp[i].first == vp[indx].first) {
        ans = max(ans, (vp[i].second - vp[indx].second));
      }
      else indx = i;
    }

    cout << "Case " << cs++ << ": " << ans << " meter(s)" << endl;
  }

  return 0;
}

