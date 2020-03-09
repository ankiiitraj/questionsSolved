// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj                                       //
//                      Problem Name    :    Even Subset Sum Problem                      //
//         		Problem Link : https://codeforces.com/contest/1323/problem/A              //
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
	int t; cin >> t; while(t--)
	{
		int n, odd = 0;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i){
			cin >> a[i];
			if(a[i]&1)
				odd++;
		}
		if(odd != n){
			cout << n - odd << endl;
			for(int i = 0; i < n; ++i)
				if(a[i]%2 == 0)
					cout << i +1 << " ";
		}else{
			if(n == 1){
				cout << -1;
			}else{
				cout << 2 << endl << 1 << " " << 2;
			}

		}
		cout << endl;
		
	}
	return 0;
}
