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
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

int find_mex(vi &a){
	si s;
	for(int i = 0; i < a.size(); ++i){
		s.insert(a[i]);
	}
	int cnt = 0;
	for(auto itr: s){
		if(itr != cnt){
			return cnt;
		}
		cnt++;
	}
	return cnt;
}

void solve(){
	int n;
	cin >> n;
	vi a(n), ans;
	scnarr(a, n);

	int i = 0;
	while(1){
		int cur_mex = find_mex(a);
		if(cur_mex >= n){
			break;
		}
		
		ans.push_back(cur_mex +1);
		a[cur_mex] = cur_mex;
	}

	for(int i = 0; i < n; ++i){
		if(a[i] != i){
			bool flag = 0;
			for(int j = i +1; j < n; ++j){
				if(a[j] == i){
					ans.push_back(j +1);
					a[j] = find_mex(a);
				}
			}
			if(!flag){
				ans.push_back(i +1);
				a[i] = find_mex(a);
			}
		}
	}

	// debug(a);

	cout << ans.size() << endl;
	for(auto itr: ans)
		cout << itr << " ";
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
	