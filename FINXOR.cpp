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
	int n, sum = 0;
	cin >> n;

	cout << "1 1048576" << endl;
	cin >> sum;
	sum -= 1048576*n;
	
	int res = 0;
	int maha_mahim = sum;
	if(sum&1)
		res += 1;
	for(int i = 1; i <= 19; ++i){
		cout << "1 " << (int)pow(2LL, i) << endl;
		cin >> sum;
		// if(sum - (int)pow(2LL, i)*n == maha_mahim){
		// 	break;
		// }
		int diff = sum - maha_mahim;
		diff = diff/(int)pow(2LL, i);
		if(diff == 0){
			if((n/2)&1)
				res += (int)pow(2LL, i);
		}else{
			if(((n - diff)/2)&1){
				res += (int)pow(2LL, i);
			}
		}
	}

	cout << "2 " << res << endl;
	cin >> sum;
}

signed main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
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
	