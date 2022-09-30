#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll ar[30005], tree[300005], n;

void set_minValue_and_index(ll node, ll start, ll end)
{
	if(start == end) {
		tree[node] = start;
		return;
	}
	
	ll Left = node * 2;
	ll Right = node * 2 + 1;
	ll mid = (start + end) / 2;
	
	set_minValue_and_index(Left, start, mid);
	set_minValue_and_index(Right, mid + 1, end);
	
	if(ar[tree[Left]] < ar[tree[Right]]) 
		tree[node] = tree[Left];
	else tree[node] = tree[Right];
}

int find_minIndex(ll node, ll b, ll e, ll start, ll end)
{
	if(b >= start and e <= end) return tree[node];

	ll Left = node * 2;
	ll Right = node * 2 + 1;
	ll mid = (b + e) / 2;
	
	if(end <= mid) return find_minIndex(Left, b, mid, start, end);
	if(start > mid) return find_minIndex(Right, mid + 1, e, start, end);
	
	ll l = find_minIndex(Left, b, mid, start, end);
	ll r = find_minIndex(Right, mid + 1, e, start, end);
	
	if(ar[l] <= ar[r]) return l;
	else return r;
	//return min(tree[l].minValue, tree[r].minValue);
}

ll area(ll start, ll end)
{
	if(start > end) return 0;
	if(start == end) return ar[start];
	ll in = find_minIndex(1, 1, n, start, end);
	
	ll ans = max(area(start, in - 1), area(in + 1, end));
	ans = max(ans, ar[in] * (end - start + 1));
	
	return ans;
}

int main()
{
	ll t;
	cin >> t;
	for(ll tc = 1; tc <= t; tc++) {
		memset(tree, 0, sizeof(tree));
		cin >> n;
		for(ll i = 1; i <= n; i++) cin >> ar[i];
		set_minValue_and_index(1, 1, n);
		cout << "Case " << tc << ": " << area(1, n) << endl;
	}
	
	return 0;
}
