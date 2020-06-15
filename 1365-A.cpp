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
		int n, m, ans = 0;
		cin >> n >> m;
		bool a[n][m];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> a[i][j];
			}
		}

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				int row = 0, col = 0;
				for(int k = 0; k < n; ++k){
					if(!a[k][j])
						row++;
				}
				for(int k = 0; k < m; ++k){
					if(!a[i][k])
						col++;
				}
				if(row == n and col == m){
					ans++;
					a[i][j] = 1;
				}
			}
		}

		if(ans&1){
			cout << "Ashish\n";
		}else{
			cout << "Vivek\n";
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	