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
const int INF = 100000000000005; // 1e15 +5

void solve(){
	int n;
	string s;
	cin >> n >> s;

	vector<int> z, o, ans(n);

	for(int i = 0; i < n; ++i){
		int new_pos = z.size() + o.size();
		if(s[i] == '0'){
			if(o.empty()){
				z.push_back(new_pos);
			}else{
				new_pos = o.back();
				z.push_back(o.back());
				o.pop_back();
			}
		}else{
			if(z.empty()){
				o.push_back(new_pos);
			}else{
				new_pos = z.back();
				o.push_back(z.back());
				z.pop_back();
			}
		}
		ans[i] = new_pos;
	}

	cout << z.size() + o.size() << endl;
	for(auto itr: ans)
		cout << itr +1 << " ";
	cout << endl;
	return;
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
	