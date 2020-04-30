#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5

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
		int n, m, ans = 0;
		cin >> n >> m;
		vi a(n);
		scnarr(a, n);
		sort(all(a));
		int i, k;
		for(i = 0, k = 1; i < n; i += m, ++k){
			int cur = 0;
			if(i + m <= n){
				for(int j = i; j < i + m; ++j){
					cur += a[j];
				}
				ans = (ans + (cur*k)%MOD)%MOD;
			}else{
				break;
			}
		}
		int cur = 0;
		for(; i < n; ++i){
			cur += a[i];
		}
		ans = (ans + (cur*(k -1))%MOD)%MOD;
		cout << ans << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	