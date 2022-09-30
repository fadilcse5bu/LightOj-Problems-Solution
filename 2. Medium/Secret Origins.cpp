#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int tc = 1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";

        ll n, m;
        cin >> n;
        vector <ll> ve;
        while(n > 0) {
            ve.push_back(n % 2);
            //cout << n << n % 2 << endl;
            n /= 2;

        }
        ve.push_back(0);

        ll in, c1 = 0;
        for(int i = 0; i < ve.size(); i++) {
            if(ve[i] == 0) {
                if(c1 > 0) {
                    in = i;
                    --c1;
                    ve[i] = 1;
                    for(int j = i - 1; j >= 0; j--) ve[j] = 0;
                    break;
                }
            }
            else ++c1;
        }

       for(int i = 0; i < in; i++) {
            if(ve[i] == 0 and c1 > 0) {
                ve[i] = 1;
                --c1;
            }
       }
        //for(int i = ve.size() - 1; i >= 0; i--) cout << ve[i] << ' ';
        //cout << endl << in << endl;

        ll v = 0, p = 0;
        for(int i = 0; i < ve.size(); i++) {
            v += (ve[i] * pow(2, p));
            ++p;
        }

        cout << v << endl;
    }

    return 0;
}
