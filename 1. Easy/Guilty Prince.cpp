#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

char ch[21][21];
int ck[21][21], ans, w, h;

void visit(int i, int j) {
  if(i < 0 or i >= w or j < 0 or j >= h) return;
  if(ch[i][j] == '#') return;
  if(ck[i][j] == 1) return;

  ++ans;
  ck[i][j] = 1;
  visit(i + 1, j);
  visit(i, j + 1);
  visit(i - 1, j);
  visit(i, j - 1);
}

int main()
{
  ll t, ca = 1;
  cin >> t;
  start:
  while(t--) {
    cin >> h >> w;
    int a, b;
    for(int i = 0; i < w; i++) {
      for(int j = 0; j < h; j++) {
        cin >> ch[i][j];
        if(ch[i][j] == '@') {
          a = i;
          b = j;
        }
        ck[i][j] = 0;
      }
    }
    ans = 0;
    visit(a, b);
    cout << "Case " << ca << ": ";
    cout << ans << endl;
    ++ca;
  }

	return 0;
}
