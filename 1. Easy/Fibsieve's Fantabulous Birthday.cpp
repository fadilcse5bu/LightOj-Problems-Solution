#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
    int tc = 1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        ll n;
        cin >> n;

        ll sr = sqrt(n);
        if(sr * sr != n) ++sr;

        ll v = sr * sr;
        ll re = v - n + 1;

        //cout << re << sr << endl;
        ll co = sr, ro = sr;
        if(sr % 2 == 0) {
            if(re <= sr) {
                ro = re;
            }
            else {
                co = sr - (re - sr);
            }
        }
        else {
            if(re <= sr) {
                co = re;
            }
            else {
                ro = sr - (re - sr);
            }
        }

        cout << co << " " << ro << endl;
    }
    return 0;
}
