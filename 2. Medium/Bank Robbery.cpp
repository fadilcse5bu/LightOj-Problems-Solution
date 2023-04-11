#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  int t = 1, cs = 1;
  scanf("%d", &t);
  while(t--) {
    ll v; cin >> v;
    cout << "Case " << cs++ << ":";
    for(ll i = 9; i >= 0; i--) {
      if((v-i)%9 == 0) {
        cout << " " << ((v-i)/9)*10 + i;
      }
    }
    cout << endl;
  }

  return 0;
}
