#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005][2];

int helper(string &s, char &c, int pos, int rpos, bool is_there){
	if(pos == rpos){
		if(is_there or s[pos] == c)
			return 1;
		return -INT_MAX;
	}else if(pos > rpos){
		if(is_there)
			return 0;
		return -INT_MAX;
	}

	if(dp[pos][rpos][is_there] != -1)
		return dp[pos][rpos][is_there];

	if(s[pos] == s[rpos]){
		if(s[pos] == c)
			return dp[pos][rpos][is_there] = helper(s, c, pos +1, rpos -1, 1) +2;
		return dp[pos][rpos][is_there] = helper(s, c, pos +1, rpos -1, 0) +2;
	}
	
	return dp[pos][rpos][is_there] = max(helper(s, c, pos, rpos -1, is_there), helper(s, c, pos +1, rpos, is_there));

}

int solve(string s, char c, int n){
	return helper(s, c, 0, n -1, 0);
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--){
		char c;
		string s;
		cin >> c >> s;
		memset(dp, -1, sizeof dp);
		cout << solve(s, c, s.length()) << endl;
	}
}