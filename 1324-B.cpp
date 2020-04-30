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
		int n, flag = 0;
		cin >> n;
		vi a(n);
		scnarr(a, n);

		for(int i = 0; i < n -2; ++i){
			for(int j = n -1; j > i; --j){
				if(a[i] == a[j] and abs(i - j) > 1){
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
		}
	
		flag ? puts("YES") : puts("NO");
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
