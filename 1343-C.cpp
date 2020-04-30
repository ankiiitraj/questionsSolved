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
const int MOD = -1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5

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
		int n, ans, res = 0, sum = 0;
		cin >> n;
		vi a(n);
		scnarr(a, n);
		a[0] > 0 ? ans = MOD : ans = MOD;
		for(int i = 0; i < n -1; ++i){
			if(a[i +1]*a[i] < 0){
				if(a[i] > 0){
					ans = max(a[i], ans);
					sum += ans;
					ans = MOD;
					res++;
				}else{
					ans = max(a[i], ans);
					sum += ans;
					ans = MOD;
					res++;
				}
			}else{
				if(a[i] > 0){
					ans = max(a[i], ans);
				}else{
					ans = max(a[i], ans);
				}
			}

		}
		if(a[n -1] > 0){
			ans = max(ans, a[n -1]);
			sum += ans;
		}else{
			ans = max(ans, a[n -1]);
			sum += ans;
		}
		cout << sum << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	