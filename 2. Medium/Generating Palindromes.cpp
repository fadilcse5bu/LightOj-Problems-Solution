#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string st;
int cnt[1005][1005];
int dp(int i, int j) {
  if(i >= j) return cnt[i][j] = 0;
  if(cnt[i][j] != -1) return cnt[i][j];

  if(st[i] == st[j]) return cnt[i][j] = dp(i+1, j-1);
  else {
    int v1 = 1 + dp(i, j-1), v2 = 1 + dp(i+1, j);
    return cnt[i][j] = min(v1, v2);
  }
}

int main()
{
  ll tc, cs = 1; //test case
  cin >> tc;
  start:
  while(tc--) {
    cin >> st;
    for(int i = 0; i <= st.size(); i++) {
      for(int j = 0; j <= st.size(); j++) {
        cnt[i][j] = -1;
      }
    }
    int ans = dp(0, st.size() - 1);
    cout << "Case " << cs++ << ": " << ans << endl;
  }

	return 0;
}


