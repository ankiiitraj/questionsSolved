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

string solve(){
	int n;
	string I, O;
	cin >> n >> I >> O;

	string res;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i == j){
				res += 'Y';
			}else if(i < j){
				bool flag = 0;
				for(int k = i; k < j; ++k){
					if(O[k] == 'N' or I[k +1] == 'N'){
						res += 'N';
						flag = 1;
						break;
					}
				}
				if(!flag){
					res += 'Y';
				}
			}else{
				bool flag = 0;
				for(int k = i; k > j; --k){
					if(O[k] == 'N' or I[k -1] == 'N'){
						res += 'N';
						flag = 1;
						break;
					}
				}
				if(!flag){
					res += 'Y';
				}
			}
		}
		res += '\n';
	}
	res.pop_back();
	return res;

}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; for(int test = 1; test <= t; ++test){
		cout << "Case #" << test << ":\n" <<  solve() << endl;
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
	