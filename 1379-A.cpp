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
	int n;
	string s, find = "abacaba";
	cin >> n >> s;
	int cnt = 0;
	for(int i = 0; i <= n -7; ++i){
		if(s.substr(i, 7) == find){
			cnt++;
		}
	}
	if(cnt == 1){
		cout << "YES\n";
		for(auto itr: s){
			if(itr == '?')
				cout << 'z';
			else
				cout << itr;
		}
		cout << endl;
		return;
	}else if(cnt > 1){
		cout << "NO\n";
		return;
	}
	int flag = 0;
	for(int i = 0; i < n; ++i){
		flag = 0;
		for(int j = i, k = 0; j < i +7; ++j, ++k){
			if(s[j] != '?' and s[j] != find[k]){
				flag = 1;
				break;
			}
		}
		if(!flag){
			string temp = s;
			for(int j = i, k = 0; j < i +7; ++j, ++k){
				temp[j] = find[k];
			}
			int cnt = 0;
			for(int m = 0; m <= n -7; ++m){
				if(temp.substr(m, 7) == find){
					cnt++;
				}
			}

			if(cnt == 1){
				s = temp;
				break;
			}
		}
	}
	if(!flag){
		cout << "YES\n";
		for(auto itr: s){
			if(itr == '?')
				cout << 'z';
			else
				cout << itr;
		}
		cout << endl;
	}else{
		cout << "NO\n";
	}


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
