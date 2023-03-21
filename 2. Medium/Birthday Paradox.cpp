#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t, cs =1 ;
  cin >> t;
  while(t--) {
    double n; cin >> n;
    double p = 1.0;
    int i = 1;
    for(i = 1; p > 0.5; i++) {
      p *= (1-i*1.0/n);
    }
    cout << "Case " << cs++ << ": " << i - 1 << endl;
  }
}
