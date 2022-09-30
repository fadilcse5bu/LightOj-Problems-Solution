#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 2 * acos(0.0)
int main()
{
    int tc = 1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        int n, m;
        cin >> n >> m;
        if(n == 1 or m == 1) {
            cout << max(n, m) << endl;
            continue;
        }
        if(n * m <= 6) {
            cout << 4 << endl;
            continue;
        }
        if(n == 2 or m == 2) {
            int ct = (n * m) / 4;
            int ans = ((ct + 1) / 2) * 4;
            if(ct % 2 == 0) ans += (n * m) % 4;
            cout << ans << endl;
            continue;
        }

        int v = (n * m + 1) / 2;

        cout << v << endl;
    }
    return 0;
}
