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

	cout << fixed << setprecision(20);
	long double p = .5, ans = 0.000000000;

	int n = 3600;

	for(int i = 1; i <= n; ++i){
		ans += (i*1.0)*(pow(p, i));

		cout << ans << " ";
		cout << endl;
	}


	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	