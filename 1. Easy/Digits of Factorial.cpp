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
        int n, b;
        cin >> n >> b;
        double ans = (n * (log10(n / M_E) / log10(b))) + ((log10(2 * M_PI * n) / log10(b)) / 2);
        int an = ans + 1;
        if(n == 0) an = 1;
        cout << an << endl;
    }
    return 0;
}
