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
const int INF = 100000000000005; // 1e15 +5

void solve(){
	string s, p, cur;
	cin >> s >> p;
	map<char, int> m;
	for(auto itr: s){
		m[itr]++;
	}
	for(auto itr: p){
		m[itr]--;
	}

	for(auto itr: m){
		int temp = itr.second;
		while(temp){
			cur += itr.first;
			temp--;
		}
	}

	if(m[p[0]] == 0){
		for(int i = 0; i < cur.length(); ++i){
			if(p[0] < cur[i]){
				cout << cur.substr(0, i) << p << cur.substr(i) << endl;
				return;
			}
		}
		cout << cur << p << endl;
		return;
	}
	int idx_s = -1, idx_e = -1;
	for(int i = 0; i < cur.length(); ++i){
		if(cur[i] == p[0]){
			idx_s = i;
			break;
		}
	}

	for(int i = cur.length() -1; i >= 0; --i){
		if(cur[i] == p[0]){
			idx_e = i;
			break;
		}
	}

	cout << min(cur.substr(0, idx_s) + p + cur.substr(idx_s), cur.substr(0, idx_e +1) + p + cur.substr(idx_e +1)) << endl;



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
	