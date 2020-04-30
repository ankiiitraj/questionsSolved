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
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		if(x == 0 and y == 0){
			cout << 0 <<endl;
			continue;
		}
		//else if(a == 0 or b == 0){
		// 	int ans1 = (max(x, y) +2)*a;
		// 	int ans2 = b + (max(x, y))*a;
		// 	cout << min(ans1, ans2) << endl;
		// 	continue;				
		// }
		int ans1 = (min(x, y))*b + (max(x, y) - min(x, y))*a;
		// int ans2 = (x -1)*a + (y -1)*a + b;
		int ans3 = (x + y)*a;
		cout << min({ans1, ans3}) << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	