#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int ar[205][105], dp[205][105];
int n;
int fun(int pos1, int pos2) {
    //cout << pos1 << ' ' << pos2 << endl;
    if(pos1 == 2 * n - 2) return ar[pos1][pos2];
    if(dp[pos1][pos2] != -1) return dp[pos1][pos2];

    if(pos1 >= n - 1) {
        if(pos2 == (n * 2 - 1 - pos1 - 1)) {
            return dp[pos1][pos2] = fun(pos1 + 1, pos2 - 1) + ar[pos1][pos2];
            //v2 += fun(pos1 + 1, pos2 - 1) + ar[pos1][pos2];
        }
        else if(pos2 == 0) {
            return dp[pos1][pos2] = fun(pos1 + 1, pos2) + ar[pos1][pos2];
            //v2 += fun(pos1 + 1, pos2) + ar[pos1][pos2];
        }
        else {
            return dp[pos1][pos2] = max(fun(pos1 + 1, pos2 - 1) + ar[pos1][pos2], fun(pos1 + 1, pos2) + ar[pos1][pos2]);

        }
    }
    else {
        return dp[pos1][pos2] = max(fun(pos1 + 1, pos2 + 1) + ar[pos1][pos2], fun(pos1 + 1, pos2) + ar[pos1][pos2]);
    }

}

int main() {
    int tc = 1;
    cin >> tc;
    int t = tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < 205; i++) {
            for(int j = 0; j < 105; j++) {
                dp[i][j] = -1;
            }
        }
        for(int i = 0; i < n * 2 - 1; i++) {
            if(i < n) {
                for(int j = 0; j <= i; j++) {
                    cin >> ar[i][j];
                }
            }
            else {
                for(int j = 0; j < n * 2 - 1 - i; j++) {
                    cin >> ar[i][j];
                }
            }

        }
        cout << "Case " << t - tc << ": " << fun(0, 0) << endl;
    }

    return 0;
}
