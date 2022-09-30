#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi acos(0.0)


int main()
{
    int tc = 1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        cout << "Case " << t << ":" << endl;
        vector <int> ve;
        vector <int> :: iterator I, II;
        int n, q;
        cin >> n >> q;
        ve.push_back(-1);
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            ve.push_back(a);
        }
        ve.push_back(200000000);

        sort(ve.begin(), ve.end());
        while(q--) {
            int l, r;
            cin >> l >> r;
            I = lower_bound(ve.begin(), ve.end(), l);
            int f = I - ve.begin();
            II = upper_bound(ve.begin(), ve.end(), r);
            int s = II - ve.begin();

            cout << s - f << endl;
        }
    }

    return 0;
}
