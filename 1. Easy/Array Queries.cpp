#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void inint(int node, int b, int e, int ar[], int tree[])
{
	if(b == e) {
		tree[node] = ar[b];
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	inint(left, b, mid, ar, tree);
	inint(right, mid + 1, e, ar, tree);
	tree[node] = min(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j, int ar[], int tree[]) 
{
	if(i > e or j < b) 
		return 100000000;
	if(b >= i and e <= j) 
		return tree[node];
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;
	int p1 = query(left, b, mid, i, j, ar, tree);
	int p2 = query(right, mid + 1, e, i, j, ar, tree);
	return min(p1, p2);
}

int main()
{
	int tc = 1;
	cin >> tc;
	for(int t = 1; t <= tc; t++) {
		cout << "Case " << t << ":" << endl;
		int n, q;
		cin >> n >> q;
		int ar[n + 1];
		int s = n * 3 + 5;
		int tree[s] = {0};
		for(int i = 1; i <= n; i++) cin >> ar[i];
		inint(1, 1, n, ar, tree);
		//cout << tree[3] << endl;
		while(q--) {
			int b, e;
			cin >> b >> e;
			cout << query(1, 1, n, b, e, ar, tree) << endl; 
		}
	}
    
    return 0;
}
