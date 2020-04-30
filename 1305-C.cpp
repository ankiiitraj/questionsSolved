// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj                                       //
//                      Problem Name    :    Kuroni and Impossible Calculation            //
//         		         Problem Link   : https://codeforces.com/contest/1305/problem/C   //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
#include <bits/stdc++.h>
#define int long long int
// #define all(a) (a.begin(), a.end())
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
		int n, m, ans = 1;
		cin >> n >> m;
		int a[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		if(n > m){
			cout << 0 << endl;
			return 0;
		}
		for(int i = 0; i < n; ++i)
			for (int j = i +1; j < n; ++j)
				ans = ans*abs(a[i] - a[j])%m;
		cout << ans << endl;
	}
	return 0;
}
