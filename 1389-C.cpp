#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define si set<int>
#define pii pair <int, int>
#define sii set<pii>
#define vii vector<pii>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace chrono;
/*
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

void solve(){
	string s;
	cin >> s;
	int n = s.length(), ans = MOD;

	for(int i = 0; i <= 9; ++i){
		for(int j = 0; j <= 9; ++j){
			string temp;
			int flag = 0;
			for(auto itr: s){
				if(itr == i + '0'){
					temp += to_string(i);
				}else if(itr == j + '0'){
					temp += to_string(j);
				}
			}
			if(temp.empty()){
				continue;
			}
			if(i != j){
				bool invert = 0;
				int cnt = 0, cnt1 = 0;
				for(int k = 0; k < temp.length(); ++k){
					if(invert and (temp[k] - '0') == i){
						cnt++;
						invert = !invert;
					}else if(!invert and (temp[k] - '0') == j){
						cnt++;
						invert = !invert;
					}
				}

				invert = 0;
				for(int k = 0; k < temp.length(); ++k){
					if(invert and (temp[k] - '0') == j){
						cnt1++;
						invert = !invert;
					}else if(!invert and (temp[k] - '0') == i){
						cnt1++;
						invert = !invert;
					}
				}
				if((cnt&1) and (cnt1&1))
					continue;
				if((cnt%2==0) and (cnt1%2==0))
					cnt = max(cnt, cnt1);
				else{
					if(cnt&1){
						cnt = cnt1;
					}
				}
				ans = min(ans, n - cnt);
				// cout << temp << " " << ans << " " << cnt << endl;
			}else{
				ans = min(ans, n - (int)temp.length());
				// cout << temp << " " << ans << endl;
			}
		}
	}
	cout << ans << endl;
	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
		solve();
	return 0;
}


//Author : Ankit Raj
//Problem Link :

/*Snippets*/
/*
sieve - prime factorization using sieve and primes in range
zpower - pow with mod
plate - Initial template
bfs 
dfs
fenwik - BIT
binary_search
segment_tree
*/
	