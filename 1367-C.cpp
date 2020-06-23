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
		int n, k, ans = 0, idx;
		string s;
		cin >> n >> k >> s;
		vi a;
		for(int i = 0; i < n; ++i){
			if(s[i] == '1')
				a.push_back(i);
		}
		if(a.size() <= 1){
			if(a.size() == 0){
				for(int i = 0; i < n; ++i){
					if(i%(k +1) == 0)
						ans++;
				}
			}else{
				for(int i = 0; i < n; ++i){
					if(s[i] == '1'){
						idx = i;
						break;
					}
				}
				if(idx > 0)
					for(int i = idx -1, j = 1; i >= 0; --i, ++j){
						if(j%(k +1) == 0)
							ans++;
					}
				if(idx < n -1)
					for(int i = idx +1, j = 1; i < n; ++i, ++j){
						if(j%(k +1) == 0)
							ans++;
					}
			}

			cout << ans << endl;
			continue;
		}
		for(int i = 0; i < a.size() -1; ++i){
			for(int j = a[i] +1, l = 1; j < a[i +1]; ++j, ++l){
				if(l%(k +1) == 0){
					ans++;
					s[j] = '1';
				}
			}
			int cnt = 0;
			for(int j = a[i +1] -1; j > a[i]; --j){
				if(s[j] == '1'){
					break;
				}
				cnt++;
			}
			if(cnt != k){
				ans--, s[i] = '0';
			}
		}
		if(s[0] != '1'){
			for(int i = a[0] -1, j = 1; i >= 0; --i, ++j){
				if(j%(k +1) == 0)
					ans++, s[i] = '1';
			}
		}
		if(s[n -1] != '1'){
			// // cout << "here\n";
			// cout << a[a.size() -1] << endl;
			for(int i = a[a.size() -1] +1, j = 1; i < n; ++i, ++j){
				if(j%(k +1) == 0)
					ans++, s[i] = '1';
			}
		}

		cout << ans << endl;
		

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	