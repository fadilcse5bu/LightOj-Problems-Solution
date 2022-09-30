#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct info {
	int sum;
} tree[300005];

void update(int node, int b, int e, int up_left, int up_right, int x)
{
	if(up_left > e or up_right < b) 
		return;
	if(b >= up_left and e <= up_right)
	{
		tree[node].sum = x;
		return;
	}
	
	int Left = node * 2;
	int Right = (node * 2) + 1;
	int mid = (b + e) / 2;
	update(Left, b, mid, up_left, up_right, x);
	update(Right, mid + 1, e, up_left , up_right, x);
	tree[node].sum = (tree[Left].sum + tree[Right].sum) % 1000000007;
}

int query(int node, int b, int e, int up_left, int up_right)
{
	if(up_left > e or up_right < b) return 0;
	if(b >= up_left and e <= up_right) {
		return tree[node].sum;
	}
	int Left = node << 1;
	int Right = (node << 1) + 1;
	int mid = (b + e) >> 1;
	
	ll p1 = query(Left, b, mid, up_left, up_right);
	ll p2 = query(Right, mid + 1, e, up_left, up_right);
	
	return (p1 + p2) % 1000000007;
}

int main()
{
	int tc;
	cin >> tc;
	for(int t = 1; t <= tc; t++){
		memset(tree, 0, sizeof(tree));
		int n;
		cin >> n;
		vector<pair<int, int>> vp;
		for(int i = 1; i <= n; i++){
			int a;
			cin >> a;
			vp.push_back({a, i});
		}
		sort(vp.begin(), vp.end());
		
		int count[n + 1] = {0}, in = 1;
		count[1] += 1 + query(1, 1, n, 1, vp[0].second);
		for(int i = 2; i <= n; i++) {
			if(vp[i - 1].first != vp[i - 2].first) {
				for(int j = in; j < i; j++) {
					update(1, 1, n, vp[j - 1].second, vp[j - 1].second, count[j]);
				}
				in = i;
			}
			count[i] += 1 + query(1, 1, n, 1, vp[i - 1].second);
			count[i] %= 1000000007;
		}
		//count[n] += 1 + query(1, 1, n, 1, vp[n - 1].second);
		//for(int i = 1; i <= n; i++) cout << count[i] << ' ';
		
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			ans += count[i];
			ans %= 1000000007;
		}
		
		cout << "Case " << t << ": " << ans << endl;
	}
	
	
	return 0;
}
