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

        double r, ans;
        cin >> r;

        ans = (r * r * 4) - (pi * r * r);
        printf("%0.2lf\n", ans);
    }
    return 0;
}
