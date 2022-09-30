#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi acos(0.0)


int main()
{
    int tc = 1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        double s = (a + b + c) / 2;
        double abc = sqrt(s * (s - a) * (s - b) * (s - c));
        double ade = (d * abc) / (d + 1);
        double ad = sqrt(ade / abc) * a;
        
        printf("%.10lf\n", ad);
    }

    return 0;
}
