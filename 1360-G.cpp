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
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		int grid[n][m] = {0};


		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j)
				grid[i][j] = 0;
		}

		if(n*a != m*b){
			cout << "NO\n";
		}else{
			vi temp(m, b);
			cout << "YES\n";
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < a; ++j){
					grid[i][(i*a + j)%m] = 1;
				}
			}

			for(int i = 0; i < n; ++i){
				for(int j = 0; j < m; ++j){
					cout << grid[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	