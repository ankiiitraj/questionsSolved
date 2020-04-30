#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 1000001; // 1e6 +1

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
		int n, q, x1, x2, y, ans;
		cin >> n >> q;
		vi a(n);
		scnarr(a, n);
		// debug(t, n, q, a);
		while(q--){
			ans = 0;
			cin >> x1 >> x2 >> y;
			--x1, --x2;
			for (int i = x1; i < x2; ++i){
				if(a[i] >= y and a[i +1] < y)
					ans++;
				else if(a[i] <= y and a[i +1] > y)
					ans++;
				else if(i +1 == x2 and a[i +1] == y and (a[i] != y))
					ans++;
			}

			cout << ans << endl;
		}
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link : https://www.codechef.com/MARCH20B/problems/LAZER
