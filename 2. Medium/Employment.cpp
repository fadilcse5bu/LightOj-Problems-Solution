#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int const N = 205;
int prefer[2*N][N], n, wPartner[N];
bool mFree[N];

bool wPrefersM1OverM(int w, int m, int m1) {
  for (int i = 1; i <= n; i++) {
    if (prefer[w][i] == m1) return true;
    if (prefer[w][i] == m) return false;
  }
}

void stableMarriage() {
  memset(wPartner, -1, sizeof(wPartner));
  memset(mFree, false, sizeof(mFree));
  queue <int> q;
  for(int i = 1; i <= n; i++) q.push(i);
  while (!q.empty()){
    int m = q.front(); q.pop();
    for (int i = 1; i <= n && mFree[m] == false; i++) {
      int w = prefer[m][i];
      if (wPartner[w] == -1){
        wPartner[w] = m;
        mFree[m] = true;
      }
      else {
        int m1 = wPartner[w];
        if (wPrefersM1OverM(w, m, m1) == false) {
          wPartner[w] = m;
          mFree[m] = true;
          mFree[m1] = false;
          q.push(m1);
        }
      }
    }
  }
}

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 1; i <= 2*n; i++) {
      for(int j = 1; j <= n; j++) {
        cin >> prefer[i][j];
      }
    }
    stableMarriage();
    cout << "Case " << cs++ << ":";
    for(int i = n+1; i <= 2*n; i++) {
      printf(" (%d %d)", wPartner[i], i);
    }
    printf("\n");
  }

	return 0;
}

