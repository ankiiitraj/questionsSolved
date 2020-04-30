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
	int t; cin >> t; while(t--)
	{
		int n, m, _min = LONG_MAX;
		cin >> n >> m;
		vi a(n), b(n), fre(m +1, -1);
		scnarr(a, n);
		scnarr(b, n);

		for (int i = 0; i < n; ++i){
			fre[a[i]] = fre[a[i]] == -1 ? 0 : fre[a[i]];
			fre[a[i]] += b[i];
		}
		for(int i = 1; i <= m; ++i)
			if(fre[i] != -1)
				_min = min(_min, fre[i]);
		cout << _min <<endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
