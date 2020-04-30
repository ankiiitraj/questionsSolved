#include<bits/stdc++.h>
using namespace std;

int n;
int memo[5005];
vector<int> a;
int solve(int idx){
	if(idx == n -1){
		if(a[idx] == 0)
			return 0;
		return 1;
	}
	if(idx == n -2){
		if(a[idx] == 0)
			return 1;
		return 2;
	}
	if(memo[idx] != -1)
		return memo[idx];
	if(a[idx] == 0)
		memo[idx] = solve(idx +1);
	else if(a[idx] <= 1)
		memo[idx] = solve(idx +1) + solve(idx +2);
	else if(a[idx] <= 2 and a[idx +1] <= 6)
		memo[idx] = solve(idx +1) + solve(idx +2);
	else
		memo[idx] = solve(idx +1); 

	return memo[idx];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		string s;
		cin >> s;
		n = s.length();
		a.resize(n);
		memset(memo, -1, sizeof(memo));
		for(int i = 0; i < n; ++i)
			a[i] = s[i] - '0';
		cout << solve(0) << endl;
	}
	return 0;
}