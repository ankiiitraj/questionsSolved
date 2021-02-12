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

vi a;

int bs(int low, int high, int n) 
{ 
    int mid = low + (high - low)/2, idx;
  	if(a[mid] == -1){
	  	cout <<"? "  << mid << endl;
	  	cin >> idx;
	  	a[mid] = idx;
  	}
  	
  	int a1, a0;
	if(a[mid -1] == -1){
  		cout <<"? "  << mid -1 << endl;
  		cin >> a0;
	  	a[mid -1] = a0;
  	}
  	if(a[mid +1] == -1){
	  	cout <<"? "  << mid +1 << endl;
	  	cin >> a1;
  		a[mid +1] = a1;
  	}
  	if(a[mid] < a[mid +1] and a[mid] < a[mid -1]) return mid;
  	
    else if (mid > 0 && a[mid -1] < a[mid]) return bs(low, (mid -1), n); 

    return bs((mid + 1), high, n); 
} 

void solve(){
	int n;
	cin >> n;

	a = vi(n +2, -1);
	a[0] = a[n +1] = INF;
	int idx = bs(0, n +1, n +1);
	cout << "! " << idx << endl;

	return;
}

signed main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
	// int t; cin >> t; while(t--)
		solve();
	return 0;
}


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
