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
		int n, k, ans = -1, idx;
		cin >> n >> k;
		vi a(n);
		scnarr(a, n);

		int peaks = 0;
		for(int i = 0; i <= n - k; ++i){
			if(i == 0){
				for(int j = i +1; j < i + k -1; ++j){
					if(a[j] > a[j +1] and a[j] > a[j -1]){
						peaks++;
					}
				}
			}else{
				if(a[i] > a[i -1] and a[i] > a[i +1]){
					peaks--;
				}
				if(a[i + k -2] > a[i + k -1] and a[i + k -2] > a[i + k -3]){
					peaks++;
				}
			}

			if(peaks > ans){
				ans = peaks;
				idx = i;
			}
		}
		
		cout << ans +1 << " " << idx +1 << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	