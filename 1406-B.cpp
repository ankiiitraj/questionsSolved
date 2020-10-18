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
	vi a(n), pos, neg;
	scnarr(a, n);
	int ans = 1;
	if(n == 5){
		for(int i = 0; i < n; ++i){
			ans = ans * a[i];
		}
		cout << ans << endl;
		return;
	}
	for(auto itr: a){
		if(itr < 0){
			neg.push_back(itr);
		}else{
			pos.push_back(itr);
		}
	}
	if(pos.size() == 0 and neg.size() == 0){
		ans = 0;
	}else if(pos.size() == 0){
		sort(all(neg));
		reverse(all(neg));
		if(neg.size() < 5){
			ans = 0;
		}else{
			for(int i = 0; i < 5; ++i){
				ans = ans*neg[i];
			}
		}
	}else if(neg.size() == 0){
		sort(all(pos));
		reverse(all(pos));
		if(pos.size() < 5){
			ans = 0;
		}else{
			for(int i = 0; i < 5; ++i){
				ans = ans*pos[i];
			}
		}
	}else{
		sort(all(pos));
		sort(all(neg));
		int si_pos = pos.size(), si_neg = neg.size(), res = -INF;
		if(si_neg + si_pos < 5){
			ans = 0;
		}else{
			if(si_pos >= 5){
				res = max(res, pos[si_pos -1]*pos[si_pos -2]*pos[si_pos -3]*pos[si_pos -4]*pos[si_pos -5]);
			}
			if(si_pos >= 3 and si_neg >= 2){
				res = max(res, pos[si_pos -1]*pos[si_pos -2]*pos[si_pos -3]*neg[0]*neg[1]);
			}
			if(si_pos >= 1 and si_neg >= 4){
				res = max(res, pos[si_pos -1]*neg[2]*neg[3]*neg[0]*neg[1]);	
			}
			ans = res;
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
	