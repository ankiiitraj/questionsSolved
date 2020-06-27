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
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), b(m);
	scnarr(a, n);
	scnarr(b, m);

	int i = 0, j = 0, ans = 0, t = 0;
	while(t + min(a[i], b[j]) <= k){
		if(i < n and j < m){

			int new_time_in_a = 0, new_time_in_b = 0, i_a = i, j_b = j;

			while(i_a < n and t + new_time_in_a + a[i_a] <= k){
				new_time_in_a += a[i_a++];
			}
			while(j_b < m and t + new_time_in_b + b[j_b] <= k){
				new_time_in_b += b[j_b++];
			}

			if(abs(i - i_a) > abs(j - j_b)){
				ans += abs(i - i_a);
				i = i_a;
				t += new_time_in_a;
			}else if(abs(i - i_a) < abs(j - j_b)){
				ans += abs(j - j_b);
				j = j_b;
				t += new_time_in_b;
			}else{
				if(new_time_in_a < new_time_in_b){
					ans += abs(i - i_a);
					i = i_a;
					t += new_time_in_a;
				}else{
					ans += abs(j - j_b);
					j = j_b;
					t += new_time_in_b;
				}
			}

		}
		else if(i < n){
			t += a[i++];
			ans++;
		}else if(j < m){
			t += b[j++];
			ans++;
		}else{
			break;
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
		