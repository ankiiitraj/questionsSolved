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
	int t; scanf("%lld", &t); while(t--)
	{
		int n, ans = 0;
		scanf("%lld", &n);
		vector<pii> a(n);
		for (int i = 0; i < n; ++i){
			scanf("%lld%lld", &a[i].first, &a[i].second);
		}

		for(int i = 0; i < n; ++i){
			if(i == 0 and a[0].first > a[n -1].second){
				ans += max(a[0].first - a[n -1].second, 0LL);
				a[0].first = a[n -1].second;
			}else if(a[i].first > a[i -1].second){
				ans += max(a[i].first - a[i -1].second, 0LL);
				a[i].first = a[i -1].second;
			}
		}
		sort(all(a));
		ans += a[0].first;
		
		cout << ans << endl;
	}
	return 0;
}



//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	