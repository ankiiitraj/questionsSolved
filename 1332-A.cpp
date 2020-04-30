#include <bits/stdc++.h>
#define int long long int
#define len length
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
		int a, b, c, d, x, y, x1, y1, x2, y2, res = 0;
		cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;

		if(a == b and x1 == x2 and a != 0){
			puts("NO");
			continue;	
		}
		if(c == d and y1 == y2 and c != 0){
			puts("NO");
			continue;
		}
		abs(b - a) <= abs(abs(x - x1) - abs(x2 - x)) and abs(d - c) <= abs(abs(y - y1) - abs(y2 - y)) ? puts("YES") : puts("NO"); 
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	