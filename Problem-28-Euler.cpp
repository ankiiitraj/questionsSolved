// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//                               Author : Ankit Raj
//                      Problem Name    :    Number spiral diagonals
//         		Problem Link : https://projecteuler.net/problem=28
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
	// int t;cin >> t;while (t--) 
	{

		int numberOfTimes = 500, ans = 4, total = 0;
		for(int i = 0; i < numberOfTimes; ++i)
		{
			ans += 8*(i) +2 + 8*(i) +4 + 8*(i) +6 + 8*(i) +8;
			total += ans;
		}
		cout << total +1<< endl;
	}
	return 0;
}