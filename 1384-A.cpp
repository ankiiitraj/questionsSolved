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
	char c = 0;
	string prev;
	for(int i = 0; i < max(1LL, a[0]); ++i){
		cout << (char)(c + 'a');
		prev += (char)(c + 'a');
	}
	cout << endl;
	for(int i = 0; i < n -1; ++i){
		if(a[i] == 0){
			c++;
			c %= 26;
			cout << (char)(c + 'a');
			prev.clear();
			prev += (char)(c + 'a');
		}else{
			prev = prev.substr(0, a[i]);
			cout << prev;
		}
		if(a[i] < a[i +1]){
			c++;
			c%=26;
			for(int j = 0; j < a[i +1] - a[i]; ++j){
				cout << (char)(c + 'a');
				prev += (char)(c + 'a');
			}
		}
		cout << endl;
	}
	if(a[n -1] == 0){
		c++;
		c%=26;
		prev = (char)(c + 'a');
	}else{
		prev = prev.substr(0, a[n -1]);
	}
	cout << prev << endl;
	
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
	