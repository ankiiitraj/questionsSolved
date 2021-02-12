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
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

void solve(){
	int atk, lyf, n;
	cin >> atk >> lyf >> n;
	vi a(n), b(n);
	scnarr(a, n);
	scnarr(b, n);

	if(n == 1){
		int req1 = b[0]/atk + (b[0] % atk == 0 ? 0 : 1), req2 = lyf/a[0] + (lyf % a[0] == 0 ? 0 : 1);
		
		if(req1 <= req2){
			cout << "YES";
		}else{
			cout << "NO";
		}
		return;
	}

	for(int i = 0; i < n; ++i){
		// debug(lyf, b);
		int req = b[i]/atk;
		if(lyf - req * a[i] <= 0){
			if(i == n -1 and lyf > 0 and atk >= b[i])
				break;
			else
				cout << "NO";
			return;
		}
		b[i] -= atk * req;
		lyf -= a[i] * req;
	}
	vii mons;
	for(int i = 0; i < n; ++i){
		if(b[i] > 0)
			mons.push_back({a[i], b[i]});
	}
	n = mons.size();
	sort(all(mons));
	for(int i = 0; i < n; ++i){
		if(i == n -1){
			if(lyf > 0){
				cout << "YES";
			}else{
				cout << "NO";
			}
			return;
		}
		lyf -= mons[i].first;
	}
	cout << "YES";
	return;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--){
		solve();
		cout << endl;
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
