#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1, cs = 1;
	string a, b;
	cin >> t;
	getline(cin, a);
	while (t--) {
    getline(cin,a);
    getline(cin,b);

    string st, st2;
    for(int i = 0; i < a.size(); i++) {
      if(a[i] == ' ') continue;
      if(a[i] >= 'a' && a[i] <= 'z') a[i] -= 32;
      st.push_back(a[i]);
    }
    for(int i = 0; i < b.size(); i++) {
      if(b[i] == ' ') continue;
      if(b[i] >= 'a' && b[i] <= 'z') b[i] -= 32;
      st2.push_back(b[i]);
    }

    sort(st.begin(), st.end());
    sort(st2.begin(), st2.end());

    cout << "Case " << cs++ << ": ";
    if(st == st2) cout << "Yes" << endl;
    else cout << "No" << endl;
	}

	return 0;
}
