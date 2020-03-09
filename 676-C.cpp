// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj                                       //
//                      Problem Name    :    Vasya and Substring                          //
//         		Problem Link : https://codeforces.com/contest/676/problem/C               //
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

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		int n, k, j = 0, i = 0, ans = -1, tempK;
		string s;
		cin >> n >> k >> s;
		tempK = k;

		while(j < n){
			if(s[j] == 'a'){
				++j;
			}else if(s[j] == 'b' and tempK > 0){
				tempK--;
				++j;
			}else{
				ans = max(ans, j - i);
				if(s[i] == 'b'){
					tempK++;
				}
				++i;
			}
		}
		ans = max(ans, j - i);
		
		i = j = 0; tempK = k;
		while(j < n){
			if(s[j] == 'b'){
				++j;
			}else if(s[j] == 'a' and tempK > 0){
				tempK--;
				++j;
			}else{

				ans = max(ans, j - i);
				if(s[i] == 'a'){
					tempK++;
				}
				++i;
			}
		}
		ans = max(ans, j - i);

		cout << ans << endl;

	}
	return 0;
}
