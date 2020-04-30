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
		int n, flag = 0;
		cin >> n;
		vector<pii> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i].first >> a[i].second;
		}
		if(a[0].first < a[0].second){
			puts("NO");
			continue;
		}else if(n == 1){
			puts("YES");
			continue;
		}
		for(int i = 1; i < n; ++i){
			if(a[i].first - a[i -1].first < a[i].second - a[i -1].second){
				flag = 0;
				break;
			}else if(a[i].first >= a[i -1].first and a[i].second >= a[i -1].second and a[i].first >= a[i].second){
				flag = 1;
			}else{
				flag = 0;
				break;
			}
		}
		flag ? puts("YES") : puts("NO");

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :