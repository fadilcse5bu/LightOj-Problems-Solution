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
        int a, b;
        cin >> a >> b;
        cout << 19 + 4 * a + abs(a - b) * 4 << endl;
    }
    return 0;
}
