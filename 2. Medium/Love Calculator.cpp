#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1.insert(0,"0");
    s2.insert(0,"1");
    ll sLen[31][31];
    ll uniq[31][31];
    for(int i = 0; i <= m; i++) sLen[0][i] = i, uniq[0][i] = 1;
    for(int i = 0; i <= n; i++) sLen[i][0] = i, uniq[i][0] = 1;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        if(s1[i] == s2[j]) {
          sLen[i][j] = sLen[i-1][j-1] + 1;
          uniq[i][j] = uniq[i-1][j-1];
        }
        else {
          sLen[i][j] = min(sLen[i][j-1], sLen[i-1][j]) + 1;
          if(sLen[i][j-1] == sLen[i-1][j]) {
            uniq[i][j] = uniq[i][j-1] + uniq[i-1][j];
          }
          else {
            uniq[i][j] = min(uniq[i][j-1], uniq[i-1][j]);
          }
        }
      }
    }

    cout << "Case " << cs++ << ": " << sLen[n][m] << ' ' << uniq[n][m] << endl;
  }

  return 0;
}
