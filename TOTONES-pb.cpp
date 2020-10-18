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

string to_binary(int n){
	string res;
	while(n){
		res += (n%2 == 0 ? '0' : '1');
		n /= 2;
	}
	reverse(all(res));
	return res;
}

void solve(){
	int n, l, r, ans = 0;
	cin >> n >> l >> r;

	string bin_n = to_binary(n), base;
	int base_cnt;

	if(bin_n.length() > 1){
		base = bin_n[1] == '0' ? "101" : "111";
		base_cnt = bin_n[1] == '0' ? 2 : 3;
	}else{
		if(n == 0){
			cout << "0\n";
		}else{
			cout << "1\n";
		}
		return;
	}

	int log_l = log2(l), log_r = log2(r);

	for(int i = log_l; i <= log_r; ++i){
		if(bin_n[i] == '1'){
			ans++;
		}
	}
	ans += (((r - l +1) - (log_r - log_l +1))/base_cnt) + ((r - l +1) - (log_r - log_l +1)) % base_cnt;
	cout << ans << endl;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
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
	