#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[21][3], n;
int fun(int pos, int in, vector <int> ve[]) {
    if(pos == n) return ve[pos][in];
    if(dp[pos][in] != -1) return dp[pos][in];

    if(in == 0) {
        int v1 = fun(pos + 1, 1, ve) + ve[pos][in];
        int v2 = fun(pos + 1, 2, ve) + ve[pos][in];
        dp[pos][in] = min(v1, v2);
    }
    if(in == 1) {
        int v1 = fun(pos + 1, 0, ve) + ve[pos][in];
        int v2 = fun(pos + 1, 2, ve) + ve[pos][in];
        dp[pos][in] = min(v1, v2);
    }
    if(in == 2) {
        int v1 = fun(pos + 1, 1, ve) + ve[pos][in];
        int v2 = fun(pos + 1, 0, ve) + ve[pos][in];
        dp[pos][in] = min(v1, v2);
    }


    return dp[pos][in];
}

int main() {
    int k;
    cin >> k;
    for(int tc = 1; tc <= k; tc++) {
        cin >> n;
        vector <int> ve[n + 1];
        for(int i = 1; i <= n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            ve[i].push_back(a);
            ve[i].push_back(b);
            ve[i].push_back(c);
        }

        for(int i = 0; i < 21; i++)
            for(int j = 0; j < 3; j++) dp[i][j] = -1;


        cout << "Case " << tc << ": " << min(fun(1, 0, ve), min(fun(1, 1, ve), fun(1, 2, ve))) << endl;
    }

    return 0;
}
