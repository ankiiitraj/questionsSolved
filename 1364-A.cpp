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
		int n, x, cnt = 0, sum = 0;
		cin >> n >> x;
		vi a(n);
		scnarr(a, n);
		for(int i = 0; i < n; ++i){
			if(a[i]%x == 0)
				cnt++;
			sum += a[i];
		}
		if(cnt == n)
			cout << -1 << endl;
		else{
			if(sum%x == 0){
				int ans = -1;
				for(int i = 0; i < n; ++i){
					if((sum - a[i])%x != 0){
						ans = max({ans, i, n - i -1});
					}
				}
				cout << ans << endl;
			}
			else
				cout << n << endl;
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	