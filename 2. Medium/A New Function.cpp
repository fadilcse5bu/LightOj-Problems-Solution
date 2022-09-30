#include <bits/stdc++.h>
using namespace std;
long long sum_all_divisors(long long num)
{
  long long sum = 0;
  for (long long i = 2; i <= sqrt(num); i++) {
    long long t1 = i * (num / i - i + 1);
    long long t2 = (((num / i) * (num / i + 1)) / 2) - ((i * (i + 1)) / 2);
    sum += t1 + t2;
  }
  return sum;
}
int main()
{
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    long long csod = sum_all_divisors(n);
    cout << "Case " << tc << ": " << csod << endl;
  }

  return 0;
}
