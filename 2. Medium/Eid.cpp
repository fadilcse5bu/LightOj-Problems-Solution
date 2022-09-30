#include <bits/stdc++.h>
using namespace std;

bool col[10001];
vector <int> prime;
void sieve() {
  for(int i = 3; i <= 100; i += 2) {
    if(col[i] == false) {
      for(int j = i*i; j <= 10000; j += 2*i) {
        col[j] = true;
      }
    }
  }
  prime.push_back(2);
  for(int i = 3; i <= 10000; i += 2){
    if(col[i] == false) prime.push_back(i);
  }
}

string lcm;
void multiply(int n) {
  int carry = 0;
  string tem;
  for(int i = lcm.size() - 1; i >= 0; i--) {
    int val = (lcm[i] - '0') * n + carry;
    char ch = (val%10) + '0';
    tem.push_back(ch);
    val /= 10;
    carry = val;
  }
  while(carry != 0) {
    char ch = (carry%10) + '0';
    carry /= 10;
    tem.push_back(ch);
  }
  reverse(tem.begin(), tem.end());
  lcm = tem;
}

int main()
{
  sieve();
  int t, tc = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    map <int, int> mp;
    for(int i = 0; i < n; i++) {
      int a;
      cin >> a;
      for(int j = 0; j < prime.size() && a > 1; j++) {
        int ct = 0;
        while(a % prime[j] == 0) {
          ++ct;
          a /= prime[j];
        }
        mp[prime[j]] = max(mp[prime[j]], ct);
      }
    }

    lcm = "1";
    for(int i = 0; i < prime.size(); i++) {
      for(int j = 0; j < mp[prime[i]]; j++) {
        multiply(prime[i]);
      }
    }

    cout << "Case " << tc++ << ": " << lcm << endl;
  }

  return 0;
}
