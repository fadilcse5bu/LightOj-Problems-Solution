#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dis[1005];

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    int n, k, low = 0, high = 0;
    cin >> n >> k;
    for(int i = 0; i <= n; i++) {
      cin >> dis[i];
      high += dis[i];
    }

    int result = -1, div = 0;
    while(low <= high) {
      int ct = 1, mid = (low + high) / 2, sum = 0;
      bool isPossible = true;
      for(int i = 0; i <= n; i++) {
        if(dis[i] > mid) {
          isPossible = false;
          break;
        }
        sum += dis[i];
        if(sum > mid) {
          ++ct;
          sum = dis[i];
        }
        if(ct > k + 1) {
          isPossible = false;
          break;
        }
      }

      if(isPossible) {
        result = mid;
        div = ct;
        high = mid - 1;
      }
      else {
        low = mid + 1;
      }
    }

    int df = n - k, sum = dis[0];
    vector <int> ans;
    for(int i = 1; i <= n; i++) {
      if(df > 0 && sum + dis[i] <= result) {
        sum += dis[i];
        --df;
      }
      else {
        ans.push_back(sum);
        sum = dis[i];
      }
    }
    if(sum > 0) ans.push_back(sum);

    cout << "Case " << cs++ << ": " << result << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  }

	return 0;
}

