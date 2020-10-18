#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
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
	----------------------------------------------------------------------
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

void solve(){
	int n, k, cnt = 0;
	string s;
	cin >> n >> k >> s;

	for(auto itr: s)
		if(itr == '?')
			cnt++;

	if(cnt == 0){
		cnt = 0;
		for(int i = 0; i < k; ++i){
			if(s[i] == '0')
				cnt++;
		}
		if(cnt != k/2){
			cout << "NO\n";
			return;
		}
		for(int i = 1, j = k; j < n; ++j, ++i){
			if(s[i -1] == '0')
				cnt--;
			if(s[j] == '0')
				cnt++;
			if(cnt != k/2){
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
		return;
	}else if(cnt == n){
		cout << "YES\n";
		return;
	}else{
		for(int i = 0; i < k; i++){
			bool z_flag = 0, o_flag = 0;
			for(int j = i; j < n; j += k){
				if(s[j] != '?'){
					if(s[j] == '1' and !z_flag){
						o_flag = 1;
					}else if(s[j] == '0' and !o_flag){
						z_flag = 1;
					}else{
						cout << "NO\n";
						return;
					}
				}
			}
			if(z_flag or o_flag){
				for(int j = i; j < n; j += k){
					if(z_flag and s[j] == '?')
						s[j] = '0';
					else if(o_flag and s[j] == '?')
						s[j] = '1';
				}
			}
		}
		int z_cnt = 0, o_cnt = 0;
		for(int i = 0; i < k; ++i){
			if(s[i] == '0')
				z_cnt++;
			if(s[i] == '1')
				o_cnt++;
		}
		if(z_cnt > k/2 or o_cnt > k/2){
			cout << "NO\n";
			return;
		}
		for(int i = 0; i < k; ++i){
			if(s[i] == '?' and z_cnt < k/2){
				z_cnt++;
				for(int j = i; j < n; j += k){
					if(s[j] == '?'){
						s[j] = '0';
					}
				}
			}else if(s[i] == '?' and o_cnt < k/2){
				o_cnt++;
				for(int j = i; j < n; j += k){
					if(s[j] == '?'){
						s[j] = '1';
					}
				}
			}
		}
		cnt = 0;
		for(int i = 0; i < k; ++i){
			if(s[i] == '0')
				cnt++;
		}	
		if(cnt != k/2){
			cout << "NO\n";
			return;
		}
		for(int i = 1, j = k; j < n; ++j, ++i){
			if(s[i -1] == '0')
				cnt--;
			if(s[j] == '0')
				cnt++;
			if(cnt != k/2){
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
		return;
	}
	return;	
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
	