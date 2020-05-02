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
	int t; cin >> t; while(t--)
	{
		int n, k;
		cin >> n >> k; 
		vi a(n), ans, pre(n);
		scnarr(a, n);
		pre[0] = a[0];

		for(int i = 0; i < k; ++i)
			ans.push_back(a[i]);
		for(int i = 1; i < n; ++i){
			pre[i] = pre[i -1] + a[i];
		}
		
		int _max = pre[k -1];

		for(int i = k; i < n; ++i){
			_max = max(_max, pre[i] - pre[i - k]);
		}

		for(int i = 0; i < n; ++i){
			
		}


	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	