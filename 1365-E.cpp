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
		int n;
		cin >> n;
		vi a(n);
		scnarr(a, n);
		sort(all(a), greater<int>());

		if(n == 1){
			cout << a[0] << endl;
		}else if(n == 2){
			cout << (a[0] | a[1]) << endl;
		}else if(pow(2, (int)log2(a[0]) +1) -1 == a[0]){
			cout << a[0] << endl;
		}else{
			int ans = -1;
			for(int i = 0; i < n; ++i){
				for(int j = i +1; j < n; ++j){
					for(int k = j +1; k < n; ++k){
						ans = max(ans, a[k] | a[i] | a[j]);
					}
				}
			}
			cout << ans << endl;
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :