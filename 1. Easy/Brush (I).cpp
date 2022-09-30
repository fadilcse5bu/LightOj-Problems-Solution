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
        int n;
        cin >> n;
        int s = 0;
        while(n--) {
            int a;
            cin >> a;
            if(a > 0) s += a;
        }

        cout << s << endl;
    }
    return 0;
}
