#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void internalUpdate(ll indx, ll ml, ll ad, ll mul[], ll add[], ll n)
{
    while(indx <= n) {
        mul[indx] += ml;
        add[indx] += ad;
        indx += (indx & -indx);
    }
}

void update(ll left, ll right, ll val, ll mul[], ll add[], ll n)
{
    internalUpdate(left, val, -val * (left - 1), mul, add, n);
    internalUpdate(right + 1, -val, val * right, mul, add, n);
}

ll sumOfRange(ll indx, ll mul[], ll add[])
{
    ll ml = 0, ad = 0, start = indx;
    while(indx > 0) {
        ml += mul[indx];
        ad += add[indx];
        indx -= (indx & -indx);
    }

    return ml * start + ad;
}

int main()
{
    int tc = 1;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
        cout << "Case " << t << ":" << endl;

        string st;
        cin >> st;
        ll n = st.size();
        ll mul[n + 1]= {0}, add[n + 1] = {0};

        int q;
        cin >> q;
        while(q--) {
            char ch;
            cin >> ch;
            getchar();
            if(ch == 'I') {
                ll i, j, val;
                cin >> i >> j;
                update(i, j, 1, mul, add, n);
            }
            else {
                ll i;
                cin >> i;
                ll v = sumOfRange(i, mul, add) - sumOfRange(i - 1, mul, add);
                if(v % 2 == 0) cout << st[i - 1] << endl;
                else {
                    if(st[i - 1] == '0') cout << '1' << endl;
                    else cout << '0' << endl;
                }
            }
        }
    }


    return 0;
}
