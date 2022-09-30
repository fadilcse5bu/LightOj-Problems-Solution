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
        ll a, b, c;
        cin >> a >> b >> c;
        if(a*a + b*b == c * c or a*a + c*c == b * b or b*b + c*c == a * a) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
