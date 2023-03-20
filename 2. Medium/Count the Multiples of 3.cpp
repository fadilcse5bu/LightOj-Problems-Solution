#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll const N = 300005;
ll tree[N][4];

void Set(int node, int b, int e, int i, int j) {
  if(i > e or j < b) return;
  if(b >= i and e <= j) {
    tree[node][0] = 1;
    return;
  }
  int L = node * 2, R = (node * 2) + 1;
	int mid = (b + e) / 2;
	Set(L, b, mid, i, j);
	Set(R, mid + 1, e, i , j);
	tree[node][0] = tree[L][0] + tree[R][0];
}

void update(int node, int b, int e, int i, int j) {
	if(i > e or j < b) return;
	if(b >= i and e <= j) {
    ll r0 = tree[node][0], r1 = tree[node][1], r2 = tree[node][2];
		tree[node][0] = r2;
		tree[node][1] = r0;
		tree[node][2] = r1;
		tree[node][3] += 1;
		return;
	}
	int L = node * 2, R = (node * 2) + 1;
	int mid = (b + e) / 2;
	update(L, b, mid, i, j);
	update(R, mid + 1, e, i , j);
	ll r = tree[node][3]%3;
	ll r0 = 0, r1 = 1, r2 = 2;
	if(r == 1) r0 = 2, r1 = 0, r2 = 1;
	else if(r == 2) r0 = 1, r1 = 2, r2 = 0;

	tree[node][0] = tree[L][r0] + tree[R][r0];
	tree[node][1] = tree[L][r1] + tree[R][r1];
	tree[node][2] = tree[L][r2] + tree[R][r2];
}

ll query(int node, int b, int e, int i, int j, ll carry = 0) {
	if(i > e or j < b) return 0;
	if(b >= i and e <= j) {
    ll r = carry%3;
    if(r == 0) return tree[node][0];
    else if(r == 1) return tree[node][2];
    else return tree[node][1];
	}
	int L = node << 1, R = (node << 1) + 1;
	int mid = (b + e) >> 1;

	ll p1 = query(L, b, mid, i, j, carry + tree[node][3]);
	ll p2 = query(R, mid + 1, e, i, j, carry + tree[node][3]);

	return (p1 + p2);
}

int main()
{
  int t = 1, cs = 1;
  cin >> t;
  while(t--) {
    int n, q; cin >> n >> q;
    memset(tree, 0, sizeof(tree));
    for(int i = 1; i <= n; i++) Set(1, 1, n, i, i);
    cout << "Case " << cs++ << ":\n";
    while(q--) {
      int tp, x, y; cin >> tp >> x >> y;
      ++x, ++y;
      if(tp == 0) {
        update(1, 1, n, x, y);
      }
      else {
        ll ans = query(1, 1, n, x, y);
        cout << ans << endl;
      }
    }
  }

	return 0;
}

/*
1
10 9
0 0 9
0 3 7
0 1 4
1 1 7
0 2 2
1 2 4
1 8 8
0 5 8
1 6 9

4 1000
0 0 3
0 0 1
0 2 2
0 2 3
1 0 3

Case 1:
2
3
0
2

*/

