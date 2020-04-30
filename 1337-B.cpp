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

int solve(int x, int n, int m){

}

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int x, n, m, flag = 0;
		cin >> x >> n >> m;

		while(x/2 +10 < x and n > 0){
			x = x/2 +10;
			n--;
		}

		if(x <= m*10)
			puts("YES");
		else
			puts("NO");

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	