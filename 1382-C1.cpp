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
	string a, b;
	cin >> n >> a >> b;
	vi ans;
	for(int i = n -1; i >= 0; --i){
		if(i == 0 and a[0] != b[0]){
			ans.push_back(1);
			a[0] = b[0];
			

		}else if(a[i] != b[i]){
			if(a[0] == b[i]){
				ans.push_back(1);
				a[0] = a[0] == '1' ? '0' : '1';
				ans.push_back(i +1);
				for(int j = 0; j <= i; ++j){
					a[j] = a[j] == '1' ? '0' : '1';
				}

				reverse(a.begin(), a.begin() + i + 1);
				
			}else{
				ans.push_back(i +1);
				for(int j = 0; j <= i; ++j){
					a[j] = a[j] == '1' ? '0' : '1';
				}
				reverse(a.begin(), a.begin() + i +1) ;
				
			}
		}
	}

	cout << ans.size() << " ";
	for(auto itr: ans){
		cout << itr << " ";
	}
	cout << endl;

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
	