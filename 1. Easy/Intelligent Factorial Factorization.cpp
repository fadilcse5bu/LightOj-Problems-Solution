#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t, tc = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    map <int,int> mp;
    for(int i = 2; i <= n; i++) {
      int x = i;
      for(int j = 2; j <= i; j++) {
        while(x % j == 0) {
          mp[j]++;
          x /= j;
        }
      }
    }

    cout << "Case " << tc++ << ": " << n << " = ";
    int ck = 0;
    for(int i = 2; i <= n; i++) {
      if(mp[i] > 0) {
        if(ck != 0) {
          cout << " * ";
        }
        ck = 1;
        cout << i << " (" << mp[i] << ")";
      }
    }
    cout << endl;
  }

  return 0;
}
