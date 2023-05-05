#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 200005;
vector <ll> p;
bool ck[N];

void sieve() {
  p.push_back(2);
  for(ll i = 3; i < N; i += 2) {
    if(ck[i] == 1) continue;
    p.push_back(i);
    for(ll j = i*i; j < N; j += (2*i)) {
      ck[j] = 1;
    }
  }
}

int main()
{
  sieve();
  int t, cs = 1;
  cin >> t;
  while(t--) {
    ll a, b; cin >> a >> b;
    memset(ck, 0, sizeof(ck));
    if(a == 1) ck[0] = 1;

    for(ll i = 0; i < p.size() && (p[i]*p[i]) <= b; i++) {
      ll f = (a / p[i]) * p[i];
      if(a % p[i] != 0) f += p[i];
      if(f == p[i]) f += p[i];
      for(ll j = f; j <= b; j += p[i]) {
        ck[j-a] = 1;
      }
    }
    ll ct = 0;
    for(ll i = a; i <= b; i++) {
      if(ck[i-a] == 0) ct++;
    }
    cout << "Case " << cs++ << ": " << ct << endl;
  }

  return 0;
}
