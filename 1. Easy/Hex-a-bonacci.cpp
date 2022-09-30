#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 10000007

int a, b, c, d, e, f;
ll ar[10005];
int fn(int n) {
    if(n < 0) return 0;
    if(ar[n] != -1) return ar[n];
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;

    return ar[n] = ((fn(n-1) % mod)  + (fn(n-2) % mod)  + (fn(n-3) % mod) + (fn(n-4) % mod) + (fn(n-5) % mod) + (fn(n-6) % mod) ) % mod;
}

int main() {
    int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset(ar, -1, sizeof(ar));
        printf("Case %d: %d\n", caseno, fn(n) % 10000007);
    }
    return 0;
}
