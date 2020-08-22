#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string s){
	string rev_s = s;
	reverse(rev_s.begin(), rev_s.end());

	return s == rev_s;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		is_palindrome(s) ? cout << "-1\n" : cout << s << endl;
	}
}