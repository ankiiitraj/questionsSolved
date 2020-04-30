// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj										  //
//                      Problem Name    :    Mike and palindrome                          //
//         		Problem Link : https://codeforces.com/problemset/problem/798/A            //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define debug cout << "Debugging . . .\n";
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
const int N = 100005;


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while (t--)
	{
		string s;
		cin >> s;
		int n = s.len(), i = 0, j = n -1, cnt = 0;
		while(i < j){
			if(s[i] != s[j])
				cnt++;
			++i, --j;
		}	
		if(cnt == 0 and n&1){
			cout << "YES\n";
		}else if(cnt != 1){
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
	}
}