// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
//                               Author : Ankit Raj										  //
//                      Problem Name    :    Primitive Primes                             //
//         		Problem Link : https://codeforces.com/contest/1316/problem/C              //
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
	// int t; cin >> t; while (t--)
	{
		int n, m, p;
		cin >> n >> m >> p;
		vector<int> a(n), b(m);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < m; ++i)
			cin >> b[i];
	
		int ind;
		for(int i = 0; i < n; ++i){
			if(a[i]%p != 0){
				ind = i;
				break;
			}
		}
		for(int i = 0; i < m; ++i){
			if(a[ind]*b[i]%p!=0){
				cout << ind + i << endl;
				return 0;
			}
		}
	
	}
}