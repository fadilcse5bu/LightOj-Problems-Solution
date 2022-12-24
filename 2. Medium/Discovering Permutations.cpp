#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int k, n;
bool used[27];
string st;
void permutation(int pos) {
  if(k == 0) return;
  if(pos == n) {
    cout << st << endl;
    --k;
    return;
  }
  for(int i = 0; i < n; i++) {
    if(used[i] == 1) continue;
    used[i] = 1;
    st[pos] = 'A'+i;
    permutation(pos+1);
    used[i] = 0;
  }
  return;
}

int main()
{
  int t, cs = 1;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    st.clear();
    for(int i = 0; i < n; i++) {
      st.push_back('A'+i);
      used[i] = 0;
    }
    cout << "Case " << cs++ << ":\n";
    permutation(0);
  }

  return 0;
}
