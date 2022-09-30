#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n, k, ar[100005], inf = 1e9, mem[100005];

int find_pos(int pos) {
  int low = pos, high = n-1, p;
  while(low <= high) {
    int mid = (low+high)/2;
    if(ar[mid]-ar[pos] > (2*k)) high = mid-1;
    else {
      low = mid+1;
    }
  }
  return low;
}

int dp(int pos) {
  if(pos >= n) return 0;
  if(mem[pos] != -1) return mem[pos];
  int ans = inf;
  int p = find_pos(pos);
  if(p - pos >= 3) ans = min(ans, dp(p)+1);
  if(p - pos >= 4) ans = min(ans, dp(p-1)+1);
  if(p - pos >= 5) ans = min(ans, dp(p-2)+1);

  return mem[pos] = ans;
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    for(int i = 0; i <= n; i++) mem[i] = -1;
    for(int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);

    cout << "Case " << cs++ << ": ";
    int ans = dp(0);
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
  }

  return 0;
}
