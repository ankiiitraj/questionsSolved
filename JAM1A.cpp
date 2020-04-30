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
	int t; cin >> t; for(int test = 1; test <= t; ++test)
	{
		int n;
		cin >> n;
		string s[n], ans, cur;
		for(int i = 0; i < n; ++i)
			cin >> s[i];

		for(int  i = 0; i < n; ++i){
			cur = s[i];
			if(ans.empty()){
				for(int j = 0; j < cur.len(); ++i){
					if(cur[i] != '*'){
						ans += cur[i];
					}
				}
				continue;
			}
			bool ast = false;
			for(int j = 0; j < cur.len(); ++j){
				if(cur[i] == '*'){
					ast = true;
				}else{
					if(cur[i] != ans[i] and !ast){

					}
				}
			}
		}


		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	