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
// 	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; scanf("%lld", &t); while(t--)
	{
		int n, q, p, b, odd = 0;
		scanf("%lld %lld", &n, &q);
		vi a(n);
		for (int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		for (int i = 0; i < n; ++i) {
			b = __builtin_popcount(a[i]);
			if(b&1)
				odd++;
		}
		while(q--){
			scanf("%lld", &p);
			b = __builtin_popcount(p);
			if(b&1){
				printf("%lld %lld\n", odd, n - odd);
			}else{
				printf("%lld %lld\n", n - odd, odd);
			}
		}
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
