#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int col[10005], ck;
void dfs(int x, vector <int> ve[])
{
	col[x] = 1;
	for(int i = 0; i < ve[x].size(); i++) {
		if(col[ve[x][i]] == 1) {
			++ck;
			return;
		}
		if(col[ve[x][i]] == 0) dfs(ve[x][i], ve);
	}
	col[x] = 2;
}

int main()
{
	int tc;
	cin >> tc;
	for(int t = 1; t <= tc; t++) {
		memset(col, 0, sizeof(col));
		ck = 0;
		int n, ct = 1;
		cin >> n;
		
		map <string, int> mp;
		vector <int> ve[10005];
		while(n--) {
			string s1, s2;
			cin >> s1 >> s2;
			if(mp[s1] == 0)mp[s1] = ct++;
			if(mp[s2] == 0) mp[s2] = ct++;
			ve[mp[s2]].push_back(mp[s1]);
		}
		
		for(int i = 1; i < ct; i++) 
			if(col[i] == 0 and ve[i].size() > 0) dfs(i, ve);
		
		cout << "Case " << t << ": ";
		if(ck == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
