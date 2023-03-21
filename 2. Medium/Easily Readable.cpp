#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    int n; cin >> n;
    map <string, ll> mp;
    while(n--) {
      string st; cin >> st;
      if(st.size() > 3) sort(st.begin()+1, st.end()-1);
      mp[st]++;
    }
    int m; cin >> m;
    getchar();
    cout << "Case " << cs++ << ":\n";
    while(m--) {
      string st;
      getline(cin, st);
      string ss;
      ll ans = 1;
      for(int i = 0; i < st.size(); i++) {
        if(st[i] == ' ') {
          if(ss.size() == 0) continue;
          if(ss.size() > 3) sort(ss.begin()+1, ss.end()-1);
          ans *= mp[ss];
          ss.clear();
        }
        else ss.push_back(st[i]);
      }
      if(ss.size() > 0) {
        if(ss.size() > 3) sort(ss.begin()+1, ss.end()-1);
        ans *= mp[ss];
      }
      cout << ans << endl;
    }
  }

	return 0;
}



