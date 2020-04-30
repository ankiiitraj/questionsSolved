#include <bits/stdc++.h>
#define int long long int
#define len length
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
		int n, x;
		cin >> n >> x;
		vi a(n);
		scnarr(a, n);
		sort(all(a));
		int suf[n];
		suf[n -1] = a[n -1];
		for(int i = n -2; i >= 0; --i){
			suf[i] = suf[i +1] + a[i];
		}

		int cur = 0, ans = 0;
		for(int i = 0; i < n; ++i){
			cur = x*(n - i);
			if(cur <= suf[i]){
				ans = n - i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	