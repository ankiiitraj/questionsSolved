#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(), a.end()
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

int memo[100005][2], n;
vi a;

bool solve(int k, bool turn){
	int i = 0;

	if(memo[k][turn] != -1)
		return memo[k][turn];

	if(!turn){
		bool res = 0;
		for(; i < n; ++i){
			res = 0;
			if(k - a[i] >= 0){
				res = res or (solve(k - a[i], !turn));
			}else{
				break;
			}
			if(res == 0)
				
		return (memo[k][turn] = 0);
		}
		
		return (memo[k][turn] = 1);
	}else{
		bool res = 1;
		for(; i < n; ++i){
			res = 1;
			if(k - a[i] >= 0){
				res = res and (solve(k - a[i], !turn));
			}else{
				break;
			}
			if(res == 1)
				return (memo[k][turn] = 1);
		}
		return (memo[k][turn] = 0);

	}

}

int32_t main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
	// int t; cin >> t; while(t--)
	{
		int k;
		cin >> n >> k;
		a.resize(n);
		scnarr(a, n);
		memset(memo, -1, sizeof(memo));
		sort(all(a));
		(solve(k, 0) ? puts("Second") : puts("First"));
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
