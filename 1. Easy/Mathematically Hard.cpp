#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

ll pre[5000010];
void sieve()
{
  for(ll i = 1; i <= 5000005; i++) pre[i] = i;
  for(ll i = 2; i <= 5000005; i++) {
    if(pre[i] == i) {
      for(ll j = 1; j * i <= 5000005; j++) {
        pre[i * j] -= pre[i * j] / i;
      }
    }
  }
  for(ll i = 1; i <= 5000005; i++) {
    pre[i] = pre[i] * pre[i] + pre[i - 1];
  }
}

int main()
{
  sieve();
  ll t, ca = 1;
  cin >> t;
  start:
  while(t--) {
    int a, b;
    cin >> a >> b;
    cout << "Case " << ca << ": ";
    cout << pre[b] - pre[a - 1] << endl;
    ++ca;
  }

	return 0;
}
