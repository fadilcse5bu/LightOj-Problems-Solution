#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1, cs = 1;
	cin >> t;
	while (t--) {
    int n; cin >> n;
    string grid; cin >> grid;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(grid[i] == '.') {
        ++ans;
        i += 2;
      }
    }
    cout << "Case " << cs++ << ": " << ans << endl;
	}

	return 0;
}// Add some code
