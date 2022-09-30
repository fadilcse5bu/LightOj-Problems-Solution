#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t, tc = 1;
  cin >> t;
  start:
  while(t--) {
    int n;
    cin >> n;
    string st;
    cin >> st;
    cout << "Case " << tc << ": ";
    if(st == "Alice") {
      if(n % 3 == 1) cout << "Bob" << endl;
      else cout << "Alice" << endl;
    }
    else {
      if(n % 3 == 0) cout << "Alice" << endl;
      else cout << "Bob" << endl;
    }
    ++tc;
  }

  return 0;
}
