#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct info {
	int sum, value;
} tree[500005];

void update(int node, int low, int high, int index, int val, int vis) 
{
	if(low == high){
		tree[node].sum = vis;
		tree[node].value = val;
		return;
	}
	
	int Left = node * 2;
	int Right = node * 2 + 1;
	int mid = (low + high) / 2;
	
	if(index <= mid) update(Left, low, mid, index, val, vis);
	else update(Right, mid + 1, high, index, val, vis);
	
	tree[node].sum = tree[Left].sum + tree[Right].sum;
}

int query(int node, int low, int high, int index, int limit) 
{
	//--tree[node].sum;
	
	int Left = node * 2;
	int Right = node * 2 + 1;
	int mid = (low + high) / 2;
	
	if(low == high) {
		int ans = tree[node].value;
		update(1, 1, limit, low, 0, 0);
		return ans;
	}
	
	if(index <= tree[Left].sum) return query(Left, low, mid, index, limit);
	else return query(Right, mid + 1, high, index - tree[Left].sum, limit);
}

int main()
{
	int tc;
	cin >> tc;
	for(int t = 1; t <= tc; t++) {
		memset(tree, 0, sizeof(tree));
		int n, q;
		cin >> n >> q;
		int limit = n + q;
		for(int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			update(1, 1, limit, i, a, 1);
		}
		
		cout << "Case " << t << ":" << endl;
		while(q--) {
			char ch;
			cin >> ch;
			getchar();
			
			int k;
			cin >> k;
			if(ch == 'a') {
				++n;
				update(1, 1, limit, n, k, 1);
			}
			else {
				if(tree[1].sum < k) cout << "none" << endl;
				else cout << query(1, 1, limit, k, limit) << endl;
			}
		}
	}
	
	return 0;
}
