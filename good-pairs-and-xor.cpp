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
const int MAXN = 100006; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5
int fact[MAXN];

int power(int x, int y){
	int ans = 1;
	while(y > 0){
		if(y&1){
			ans = (ans * x)%MOD;
			--y;
		}else{
			x = (x * x)%MOD;
			y /= 2;
		}
	}
	return ans;
}

int nCr(int n, int r){
	int num = fact[n];
	int deno = fact[r]*fact[n - r]%MOD;
	deno = power(deno, MOD -2);
	return num*deno%MOD;
}


void solve(){
	fact[0] = 1;
	
	for(int i = 1; i <= 10005; ++i)
		fact[i] = fact[i -1]*i%MOD;

	string s;
	cin >> s;
	int n = s.length(), ans = 0;
	int idx = -1;
	for(int i = 1; i < n; ++i){
		if(s[i] == '0'){
			idx = i;
			break;
		}
	}
	int num_bits = n -1;
	if(idx == -1){
		num_bits++;
	}
	for(int i = 0; i <= num_bits; ++i){
		int num_count = nCr(num_bits, i);
		ans = (ans + (num_count * power(2, num_bits - i) % MOD)) % MOD;
	}

	int bit_count = 0;
	if(idx != -1){
		for(int i = 1; i < n; ++i){
			if(s[i] == '1'){
				bit_count++;
			}else{
				break;
			}
		}

		int num_bits = n - 2, new_ans = 0;
		for(int i = 0; i <= num_bits; ++i){
			int num_count = nCr(num_bits, i);
			new_ans = (new_ans + (num_count * power(2, num_bits - i) % MOD)) % MOD;
		}
		new_ans = (new_ans * bit_count % MOD)*2 % MOD;
		ans = (ans + new_ans) % MOD;
		new_ans == 0 ? ans += 2 : 0;

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
	// int t; cin >> t; while(t--)
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
	