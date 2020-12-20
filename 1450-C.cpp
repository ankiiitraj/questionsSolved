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
	int n;
	cin >> n;
	vector<string> s(n), p, q, r;
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}

	p = q = r = s;

	int resp, resq, resr;
	resp = resq = resr = 0;

	for(int i = 0; i < n; ++i){
		for(int j = i%3; j < n; j += 3){
			if(j < n and p[i][j] == 'X'){
				p[i][j] = 'O';
				resp++;
			}
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = (i +1)%3; j < n; j += 3){
			if(j < n and q[i][j] == 'X'){
				q[i][j] = 'O';
				resq++;
			}
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = (i +2)%3; j < n; j += 3){
			if(j < n and r[i][j] == 'X'){
				r[i][j] = 'O';
				resr++;
			}
		}
	}

	if(min({resp, resq, resr}) == resp){
		s = p;
	}else if(min({resp, resq, resr}) == resq){
		s = q;
	}else{
		s = r;
	}
	
	for(int i = 0; i < n; ++i){
		cout << s[i] << endl;
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
