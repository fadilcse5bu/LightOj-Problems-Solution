#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    string start, finish;
    cin >> start >> finish;
    int n;
    cin >> n;
    map<string, int> mp, m;
    while(n--) {
      string s1, s2, s3;
      cin >> s1 >> s2 >> s3;
      for(int i = 0; i < s1.size(); i++) {
        for(int j = 0; j < s2.size(); j++) {
          for(int k = 0; k < s3.size(); k++) {
            string st;
            st.push_back(s1[i]);
            st.push_back(s2[j]);
            st.push_back(s3[k]);
            mp[st] = 1;
          }
        }
      }
    }
    queue <pair<string, int>> q;
    q.push({start, 0});
    int ans = -1, ct = 0;
    if(mp[start] == 1) {
      cout << "Case " << cs++ << ": " << ans << endl;
      continue;
    }
    while(!q.empty()) {
      string st = q.front().first;

      int v = q.front().second;
      if(st == finish) {
        ans = v;
        break;
      }
      q.pop();
      for(int i = 0; i < 6; i++) {
        char c1 = st[0] + dx[i];
        char c2 = st[1] + dy[i];
        char c3 = st[2] + dz[i];
        if(c1 > 'z') c1 = 'a';
        else if(c1 < 'a') c1 = 'z';

        if(c2 > 'z') c2 = 'a';
        else if(c2 < 'a') c2 = 'z';

        if(c3 > 'z') c3 = 'a';
        else if(c3 < 'a') c3 = 'z';
        string ss;
        ss.push_back(c1);
        ss.push_back(c2);
        ss.push_back(c3);
        if(m[ss] == 0 && mp[ss] == 0) {
          m[ss] = 1;
          q.push({ss, v + 1});
        }
      }
    }
    cout << "Case " << cs++ << ": " << ans << endl;
  }
}

