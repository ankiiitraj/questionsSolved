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
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000001; // 1e6 +1

/* -------------------------------Solution Sarted--------------------------------------*/
int ans = 0;
int memo[1005][1005];
int count(int n, int l){
	if(n == 0)
		return 1;
	int ans = 0, i = 2;
	while(i <= n){
		if(memo[n -i][i] != -1)
			ans = (ans + memo[n -i][i])%MOD;
		else if( i <= l){
			memo[n -i][i] = (count(n - i, l))%MOD;
			ans = (ans + memo[n -i][i])%MOD;
		}
		i += 2;
	}
	return ans;
}


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, l;
		cin >> n >> l;
		memset(memo, -1, sizeof(memo));	
		cout << count(n, l) << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
