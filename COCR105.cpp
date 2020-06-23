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
		int l, r, ans = 0;
		cin >> l >> r;

		double mint = 0, hr;

		for(int i = l; i <= r; ++i){
			hr = (i%12) * 30;
			mint = 0;
			for(int j = 0; j < 60; ++j){
				for(int k = 0; k < 60; ++k){
					if(abs(hr - mint) <= 90.1 and abs(hr - mint) >= 89.9 ){
						ans++;
					}
					hr += 0.00833333333;
					mint += .1;

				}
			}
		}
		
		cout << ans << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	
