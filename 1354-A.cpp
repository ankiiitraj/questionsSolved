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
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if(b >= a){
			cout << b << endl;
		}else if(d >= c){
			cout << -1 << endl;
		}else{
			int times = (a - b)/(c - d) + ((a - b)%(c - d) == 0 ? 0 : 1);
			int ans = b + times*c;
			cout << ans << endl;
			
		}
		

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	