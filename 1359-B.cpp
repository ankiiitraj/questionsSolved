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
		int n, m, x, y, ans = 0, sna = 0;
		cin >> n >> m >> x >> y;
		string a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(j != m -1){
					if(a[i][j] == '.' and a[i][j +1] == '.'){
						ans += min(2*x, y);
						++j;
					}else if(a[i][j] == '.'){
						ans += x;
					}
				}else if(a[i][j] == '.'){
					ans += x;
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
	