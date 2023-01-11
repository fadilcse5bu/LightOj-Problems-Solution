#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1, cs = 1;
	cin >> t;
	while (t--) {
    double v1, v2, v3, a1, a2;
    cin >> v1 >> v2 >> v3 >> a1 >> a2;
    double d = (v1*v1)/(2.0*a1) + (v2*v2)/(2.0*a2);
    double t1 = v1/a1, t2 = v2/a2;
    double dd = t1*v3;
    if(t2 > t1) dd = t2*v3;
    cout << "Case " << cs++ << ": " << fixed << setprecision(9) << d << ' ' << dd << endl;
	}

	return 0;
}
