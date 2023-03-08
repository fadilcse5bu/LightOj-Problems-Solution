#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t = 1, cs = 1; 
    cin >> t;
    while(t--) {
        int n, d; cin >> n >> d;
        int ct = 1, rem = d % n;
        while(rem != 0) {
            rem = (rem*10 + d);
            rem %= n;
            ct++;
        }
        cout << "Case " << cs++ << ": " << ct << endl;
    }
}
