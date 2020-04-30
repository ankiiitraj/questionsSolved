#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 1000001; // 1e6 +1

/* -------------------------------Solution Sarted--------------------------------------*/


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		int u, v;
		cin >> u >> v;

		if(u > v){
			cout << -1 << endl;
			return 0;
		}
		if(u == v){
			if(u == 0)
				cout << "0\n";
			else
				cout << 1 << "\n" << u << endl;
			return 0;
		}
		bool a[61], b[61], curU, curV;

		for(int i = 60; i >= 0; ++i){
			curU = u&1;
			curV = v&1;

			a[i] = curV&curU;

			u = u >> 1;
			v = v >> 1;
		}
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
