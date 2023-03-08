#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll dp1[55][55][55], dp2[55][55][55], n;
string st;

bool isBad(int pos, int vow, int con) {
  if(vow == 3 or con == 5) return 1;
  if(pos >= n) return 0;
  if(dp1[pos][vow][con] != -1) return dp1[pos][vow][con];
  if(st[pos] == '?') {
    bool ck1 = isBad(pos+1, vow+1, 0);
    bool ck2 = isBad(pos+1, 0, con+1);
    return dp1[pos][vow][con] = (ck1|ck2);
  }
  else if(st[pos] == 'A' || st[pos] == 'E' || st[pos] == 'I' || st[pos] == 'O' || st[pos] == 'U') {
    return dp1[pos][vow][con] = isBad(pos+1, vow+1, 0);
  }
  else return dp1[pos][vow][con] = isBad(pos+1, 0, con+1);
}

bool isGood(int pos, int vow, int con) {
  if(pos >= n) return 1;
  if(dp2[pos][vow][con] != -1) return dp2[pos][vow][con];
  if(st[pos] == '?') {
    bool ck1 = 0;
    if(vow < 2) ck1 = isGood(pos+1, vow+1, 0);
    bool ck2 = 0;
    if(con < 4) ck2 = isGood(pos+1, 0, con+1);
    return dp2[pos][vow][con] = (ck1|ck2);
  }
  else if(st[pos] == 'A' || st[pos] == 'E' || st[pos] == 'I' || st[pos] == 'O' || st[pos] == 'U') {
    bool ck = 0;
    if(vow < 2) ck = isGood(pos+1, vow+1, 0);
    return dp2[pos][vow][con] = ck;
  }
  else {
    bool ck = 0;
    if(con < 4) ck = isGood(pos+1, 0, con+1);
    return dp2[pos][vow][con] = ck;
  }
}

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    cin >> st;
    n = st.size();
    memset(dp1, -1, sizeof(dp1));
    bool b = isBad(0,0,0);
    memset(dp2, -1, sizeof(dp2));
    bool g = isGood(0,0,0);
    cout << "Case " << cs++ << ": ";
    if(b == 1 && g == 1) cout << "MIXED" << endl;
    else if(b == 1) cout << "BAD" << endl;
    else cout << "GOOD" << endl;
  }

  return 0;
}
