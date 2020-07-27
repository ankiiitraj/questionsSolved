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

void solve(){
	int n;
	cin >> n;
	vi a(n);
	scnarr(a, n);
	bool turn = 0;
	int i = 0;
	while(a[i] == 1 and i < n){
		turn = !turn;
		++i;
	}
	i = n -1;
	while(a[i] == 1 and i >= 0){
		i--;
	}

	if(i == -1){
		if(n&1){
			cout << "First\n";
		}else{
			cout << "Second\n";
		}
	}else{
		if(turn){
			cout << "Second\n";
		}else{
			cout << "First\n";
		}
	}


	// for(int i = 0; i < n -1; ++i){
	// 	if(a[i] != 1){
	// 		int j = i +1;
	// 		while(a[j] == 1 and j < n){
	// 			++j;
	// 		}
	// 		if(j == n){
	// 			int cnt = n - i -1;
	// 			if(cnt&1){
	// 				if(turn)
	// 					cout << "First\n";
	// 				else
	// 					cout << "Second\n";
	// 			}else{
	// 				if(!turn)
	// 					cout << "First\n";
	// 				else
	// 					cout << "Second\n";
	// 			}
	// 			return;
	// 		}else{
	// 			turn = turn;
	// 		}
	// 		i = j -1;
	// 	}else{
	// 		turn = !turn;
	// 	}
	// }
	// if(!turn){
	// 	cout << "First\n";
	// }else{
	// 	cout << "Second\n";
	// }
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
	