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

bool check(vi &e, vi &r, vi &res){
	int time = 0;
	for(int i = 0; i < res.size(); ++i){
		time += e[res[i]];
	}
	for(int i = 0; i < res.size(); ++i){
		if(r[res[i]] > time - e[res[i]]){
			return 0;
		}
	}
	return 1;
}

int new_check(vi &e, vi &r, vi &res){
	int time = 0, enjoy = 0;
	for(int i = 0; i < res.size(); ++i){
		time += e[res[i]];
		enjoy += e[res[i]];
	}
	for(int i = 0; i < res.size(); ++i){
		if(r[res[i]] > time - e[res[i]]){
			return enjoy;
		}
		enjoy += e[res[i]];
	}
	return enjoy;
}

int rec(vi &r, vi &e, int pos, vi &res, int n){
	if(pos >= n){
		if(res.size() <= 1){
			return -INF;
		}
		if(check(e, r, res)){
			return res.size();
		}else{
			return -INF;
		}
	}

	int one = rec(r, e, pos +1, res, n);
	res.push_back(pos);
	int two = rec(r, e, pos +1, res, n);
	res.pop_back();

	return max(one, two);
}
int _max = -1, _max_t = -1;
void new_rec(vi &r, vi &e, int pos, vi &res, int n){
	if(pos >= n){
		if(res.size() <= 0){
			return;
		}
		if((int)res.size() > _max){
			_max = res.size();
			_max_t = new_check(e, r, res);
			return;
		}else{
			return;
		}
	}

	new_rec(r, e, pos +1, res, n);
	res.push_back(pos);
	new_rec(r, e, pos +1, res, n);
	res.pop_back();

	return;
}

void solve(){
	int n;
	cin >> n;
	vi e(n), r(n), res;
	for(int i = 0; i < n; ++i){
		cin >> e[i] >> r[i];
	}
	int ans = rec(r, e, 0, res, n);
	if(ans != -INF){
		cout << n - ans << " " << "INDEFINITELY" << endl;
	}else{
		_max_t = -1, _max = -1;
		res.clear();
		new_rec(r, e, 0, res, n);
		cout << n - _max << " " << _max_t << endl;
	}
}

signed main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
	int t; cin >> t; for(int test = 1; test <= t; ++test){
		cout << "Case #" << test << ": ";
		solve();

	}
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
		