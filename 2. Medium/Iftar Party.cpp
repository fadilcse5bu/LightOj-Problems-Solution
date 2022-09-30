#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int p, l;
    cin >> p >> l;
    int re = p - l;
    vector <int> ve;
    for(int i = 1; i <= sqrt(re); i++) {
      if(re % i == 0) {
        ve.push_back(i);
        if(i * i != re) ve.push_back(re / i);
      }
    }

    cout << "Case " << tc << ": ";
    if(re <= l) {
      cout << "impossible" << endl;
      continue;
    }

    sort(ve.begin(), ve.end());
    for(int i = 0; i < ve.size(); i++) {
      if(ve[i] > l) {
        cout << ve[i] << ' ';
      }
    }
    cout << endl;
  }

	return 0;
}
