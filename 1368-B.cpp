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

long double intlog(long double base, long double x) {
    return (long double)(log(x) / log(base));
}

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		int n;
		cin >> n;
		if(n == 1){
			cout << "codeforces\n";
			return 0;
			
		}
		long double cur = 11;
		int cnt = 2; 
		while(cur > 10){
			cur = intlog(cnt, n);
			cnt++;
		}

		int to_use = cur;
		if(to_use < cur){
			to_use++;
		}
		if(cnt -1 > 2){
			int newN = pow(cnt -2, 10);
			for(int i = 1; i <= 10; ++i){
				newN = pow(cnt -1, i)*pow(cnt -2, 10 - i);
				if(newN >= n){
					to_use = i -1;
					break;
				}
			}
			if(cur > to_use or cur == 0)
				to_use++;
		}
		// cout << to_use << " " << cnt << endl;
		string ans, co = "codeforces";
		for(int i = 0; i < to_use; ++i){
			for(int j = 0; j < cnt -1; ++j){
				ans += co[i];
			}
		}
		for(int i = to_use; i < 10; ++i)
			for(int j = 0; j < cnt -2; ++j)
			ans += co[i];

		cout << ans << endl;


	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	