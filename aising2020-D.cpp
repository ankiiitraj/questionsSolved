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
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

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

void solve(){
	int n;

	string s;
	cin >> n >> s;

	int pop_count = 0, cur_pop_count;

	for(auto itr: s){
		if(itr == '1')
			pop_count++;
	}
	int decre = 0, incre = 0;

	for(int i = 0; i < n; ++i){
		if(s[i] == '1'){
			if(pop_count -1 > 0){
				MOD = pop_count -1;
				decre += power(2LL, n - i -1);
				decre %= pop_count -1;
			}
			MOD = pop_count +1;
			incre += power(2LL, n - i -1);
			incre %= pop_count +1;
		}
	}

	for(int i = 1; i <= n; ++i){
		int rem, ans = 1;
		if(s[i -1] == '0'){
			cur_pop_count = pop_count +1;
			MOD = cur_pop_count;
			rem = incre + power(2, n - i) % cur_pop_count;
			while(rem){
				rem %= __builtin_popcount(rem);
				ans++;
			}
		}else{
			cur_pop_count = pop_count -1;
			if(cur_pop_count <= 0){
				cout << "0\n";
				continue;
			}
			MOD = cur_pop_count;
			rem = ((decre - power(2, n - i)) % MOD + MOD) % MOD;
			while(rem){
				rem %= __builtin_popcount(rem);
				ans++;
			}
		}
		cout << ans << endl;
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
