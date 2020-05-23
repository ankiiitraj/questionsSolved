#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5

/* -------------------------------Solution Sarted--------------------------------------*/

int solve(vi &a, int cur, int n){
	if(cur >= n){
		return 0;
	}
	int ans = 0;
	for(int i = 2; i*cur <= n; ++i){
		if(a[cur] < a[cur*i]){
			ans = max(ans, solve(a, cur*i, n) +1);
		}
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
		int n;
		cin >> n;
		vi a(n +1);
		scnarr(a, n);
		int res = 1;
		for(int i = 1; i <= n/2; ++i){
			int ans = 1;
			if(a[i] > a[1])
				ans++;
			ans += solve(a, i, n);
			res = max(ans, res);
		}
		cout << res << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	