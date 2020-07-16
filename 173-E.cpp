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
	int n, k;
	cin >> n >> k;
	vi a(n), pos, neg;
	scnarr(a, n);
	
	for(int i = 0; i < n; ++i){
		a[i] < 0 ? neg.push_back(a[i]) : pos.push_back(a[i]);
	}
	
	if(k == n){
		int ans = 1;
		
		for(int i = 0; i < k; ++i)
			ans = ((ans * a[i] % MOD) + MOD) % MOD;

		cout << ans << endl;
		return;
	}

	if(k&1 and pos.size() == 0){
		int ans = 1;
		sort(all(neg), greater<int>());
		for(int i = 0; i < k; ++i)
			ans = ((ans * neg[i] % MOD) + MOD) % MOD;

		cout << ans << endl;
		return;
	}

	if(pos.size() == 0){
		int ans = 1;
		sort(all(neg));
		for(int i = 0; i < k; ++i)
			ans = ans * neg[i] % MOD;

		cout << ans << endl;
		return;
	}

	if(neg.size() == 0){
		int ans = 1;
		sort(all(pos), greater<int>());
		for(int i = 0; i < k; ++i)
			ans = ans * pos[i] % MOD;

		cout << ans << endl;
		return;
	}

	sort(all(neg));
	sort(all(pos), greater<int>());

	int i = 0, j = 0, cnt = 0, ans = 1;

	if(k&1){
		ans = ans * pos[i++] % MOD;
		cnt++;
	}

	while(cnt < k){
		if(k - cnt == 1){
			ans = ans * pos[i] % MOD;
			break;
		}

		if(i != pos.size() -1 and j != neg.size() -1){
			if(pos[i]*pos[i +1] > neg[j]*neg[j +1]){
				ans = ans * pos[i] % MOD;
				ans = ans * pos[i +1] % MOD;
				i += 2;
			}else{
				ans = ans * (neg[j] * neg[j +1] % MOD) % MOD;
				j += 2;
			}
			cnt += 2;
		}else if(j == neg.size() -1){
			ans = ans * pos[i] % MOD;
			ans = ans * pos[i +1] % MOD;
			i += 2;
			cnt += 2;
		}else{
			ans = ans * (neg[j] * neg[j +1] % MOD) % MOD;
			j += 2;
			cnt += 2;
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
	