#include<bits/stdc++.h>
using namespace std;

string s;
map<string, int> memo;
int solve(string s){
	int n = s.length();
	if(s.size() == 1)
		return 1;
	if(s.size() == 2 and s[0] == s[1])
		return 2;
	if(memo.find(s) != memo.end())
		return memo[s];
	int i = 0;
	for(i = 0; i < n -1; ++i){
		if(s[i] != s[i +1])
			break;
	}
	if(i == n -1)
		return n;

	int ans = INT_MAX;
	for(int i = 0; i < n -1; ++i){
		string temp;
		if(s[i] != s[i +1]){
			temp = s.substr(0, i); 
			if(s[i] == 'a'){
				if(s[i +1] == 'b')
					temp += 'c';
				else
					temp += 'b';
			}else if(s[i] == 'b'){
				if(s[i +1] == 'a')
					temp += 'c';
				else	
					temp += 'a';
			}else{
				if(s[i +1] == 'a')
					temp += 'b';
				else
					temp += 'a';
			}
			temp += s.substr(i +2);
			ans = min(ans, solve(temp));
		}
	}
	memo.insert({s, ans});
	return ans;
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
		memo.clear();
		cout << solve(s) << endl;
	}

	return 0;
}