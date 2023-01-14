#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int i, j, m, n, c[220][220];
char b[220][220];
string x, y, tmp;

void findMatchingSequence(int i, int j) {
  if (i == 0 || j == 0) return;
  if (b[i][j] == 'c'){
    findMatchingSequence(i - 1, j - 1);
    tmp.push_back(x[i-1]);
  }
  else if (b[i][j] == 'u') findMatchingSequence(i - 1, j);
  else findMatchingSequence(i, j - 1);
}

void lcs() {
  m = x.size();
  n = y.size();
  for (i = 0; i <= m; i++) c[i][0] = 0;
  for (i = 0; i <= n; i++) c[0][i] = 0;

  for (i = 1; i <= m; i++){
    for (j = 1; j <= n; j++){
      if(x[i-1] == y[j-1]) {
        tmp.clear();
        findMatchingSequence(i-1,j-1);
        string sc = tmp;
        if(x[i-1] == y[j-1]) sc.push_back(x[i-1]);

        tmp.clear();
        findMatchingSequence(i-1,j);
        string su = tmp;

        tmp.clear();
        findMatchingSequence(i,j-1);
        string sl = tmp;

        ll lsc = sc.size(), lsu = su.size(), lsl = sl.size();
        if(lsc > lsu && lsc > lsl) {
          c[i][j] = lsc;
          b[i][j] = 'c';
        }
        else if(lsl > lsu && lsl > lsc) {
          c[i][j] = lsl;
          b[i][j] = 'l';
        }
        else if(lsu > lsc && lsu > lsl) {
          c[i][j] = lsu;
          b[i][j] = 'u';
        }
        else if(lsc == lsl) {
          if(sc <= sl) {
            c[i][j] = lsc;
            b[i][j] = 'c';
          }
          else {
            c[i][j] = lsl;
            b[i][j] = 'l';
          }
        }
        else if(lsc == lsu) {
          if(sc <= su) {
            c[i][j] = lsc;
            b[i][j] = 'c';
          }
          else {
            c[i][j] = lsu;
            b[i][j] = 'u';
          }
        }
        else if(lsl == lsu) {
          if(sl <= su) {
            c[i][j] = lsl;
            b[i][j] = 'l';
          }
          else {
            c[i][j] = lsu;
            b[i][j] = 'u';
          }
        }
      }
      else {
        tmp.clear();
        findMatchingSequence(i-1,j);
        string su = tmp;

        tmp.clear();
        findMatchingSequence(i,j-1);
        string sl = tmp;

        ll lsu = su.size(), lsl = sl.size();
        if(lsu > lsl) {
          c[i][j] = lsu;
          b[i][j] = 'u';
        }
        else if(lsl > lsu) {
          c[i][j] = lsl;
          b[i][j] = 'l';
        }
        else{
          if(su <= sl) {
            c[i][j] = lsu;
            b[i][j] = 'u';
          }
          else {
            c[i][j] = lsl;
            b[i][j] = 'l';
          }
        }
      }
    }
  }
}

int main() {
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    cin >> x >> y;
    ll lx = x.size(), ly = y.size();
    lcs();
    cout << "Case " << cs++ << ": ";
   //cout << c[lx][ly] << endl;
    if(c[lx][ly] == 0) {
      cout << ":(" << endl;
    }
    else {
      tmp.clear();
      findMatchingSequence(lx, ly);
      cout << tmp << endl;
    }
  }

  return 0;
}
