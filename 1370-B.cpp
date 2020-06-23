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
		int n;
		cin >> n;
		vi a(2*n);
		scnarr(a, 2*n);
		vector<pii> ans, odd, even;

		for(int i = 0; i < 2*n; ++i){
			if(a[i]&1){
				odd.push_back({a[i], i +1});
			}else{
				even.push_back({a[i], i +1});
			}
		}
		int cnt = even.size()&1 ? even.size() -1 : even.size();

		for(int i = 0; i < cnt; i += 2){
			ans.push_back({even[i].second, even[i +1].second});
		}

		cnt = odd.size()&1 ? odd.size() -1 : odd.size();

		for(int i = 0; i < cnt; i += 2){
			ans.push_back({odd[i].second, odd[i +1].second});
		}

		for(int i = 0; i < n -1; ++i){
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	
	}
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	