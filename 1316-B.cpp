// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj										  //
//                      Problem Name    :    String Modification                          //
//         		Problem Link : https://codeforces.com/contest/1316/problem/B              //
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
	int t; cin >> t; while (t--)
	{
		int n;
		string s, curAns, temp;
		cin >> n >> s;
		curAns = s;
		int ans = 1;
		for(int i = 1; i <= n; ++i){
			temp = s;
			if((n - i +1)&1){
				string temp2 = temp.substr(0, i -1);
				reverse(temp2.begin(), temp2.end());
				temp = temp.substr(i - 1, n - i +1) + temp2;
			}else{
				temp = temp.substr(i - 1, n - i +1) + temp.substr(0, i -1);
			}
		
			if(curAns > temp){
				curAns = temp;
				ans = i;
			}
		}
		cout << curAns << endl << ans << endl;

	}
}