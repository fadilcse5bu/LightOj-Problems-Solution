#include <bits/stdc++.h>
using namespace std;
#define ll long long int

double ev[100001];

void expected_value(int i) {
  int divisors = 1;
  double v = 2.0;
  for(int j = 2; j * j <= i; j++) {
    if(i % j == 0) {
      v += (1 + ev[j]);
      divisors++;
      if((i / j) != j) {
        v += (1.0 + ev[i / j]);
        divisors++;
      }
    }
  }
  ev[i] = (v / (divisors * 1.0));
}

void pre_cal() {
  ev[1] = 0.0;
  for(int i = 2; i <= 100000; i++) {
    expected_value(i);
  }
}

int main()
{
  pre_cal();
  int t, tc = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    cout << "Case " << tc++ << ": ";
    printf("%.10lf\n", ev[n]);
  }

  return 0;
}
