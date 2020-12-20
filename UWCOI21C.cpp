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
	int n, k;
	cin >> n >> k;
	vi a(n +1);
	scnarr(a, n +1);
	// if(k == 2){

	// 	for(int i = 0; i < n; ++i){
	// 		int c1 = -1, c2 = -1, m1 = 0, m2 = 0;
	// 		for(int j = 0; j <= n; ++j){
	// 			if(a[j] > 0 and c1 == -1){
	// 				c1 = j;
	// 				m1 = 1;
	// 				a[j]--;
	// 			}else if(a[j] > 0){
	// 				c2 = j;
	// 				m2 = 1;
	// 				a[j]--;
	// 				break;
	// 			}

	// 		}
	// 		if(c2 == -1){
	// 			a[c1]++;
	// 			for(int j = 0; j <= n; ++j){
	// 				if(a[j] > 1){
	// 					c1 = j;
	// 					m1 = 2;
	// 					c2 = j;
	// 					m2 = 0;
	// 					a[j] -= 2;
	// 					break;
	// 				}
	// 			}
	// 		}
	// 		// debug(a);
	// 		cout << c1 << " " << m1 << " " << c2 << " " << m2 << endl;
	// 	}
	// }else if(n == 2 and k == 5){
	// 	vii aa;
	// 	for(int i = 0; i <= n; ++i){
	// 		aa.push_back({a[i], i});
	// 	}
	// 	sort(all(aa));
	// 	vector<vi> res;
		
	// 	if(aa[0].first + aa[1].first == 5){
	// 		cout << aa[0].second << " " << aa[0].first << " " << aa[1].second << " " << aa[1].first << endl;
	// 		cout << aa[2].second << " " << aa[2].first << " " << 0 << " " << 0 << endl;
	// 	}else if(aa[0].first + aa[1].first < 5){
	// 		cout << aa[0].second << " " << aa[0].first << " " << aa[2].second << " " << 5 - aa[0].first << endl;
	// 		cout << aa[1].second << " " << aa[1].first << " " << aa[2].second << " " << 5 - aa[1].first << endl;
	// 	}else{
	// 		cout << aa[0].second << " " << aa[0].first << " " << aa[2].second << " " << 5 - aa[0].first << endl;
	// 		cout << aa[1].second << " " << aa[1].first << " " << aa[2].second << " " << 5 - aa[1].first << endl;
	// 	}
	// }else{
		vii aa;
		for(int i = 0; i <= n; ++i){
			aa.push_back({a[i], i});
		}
		sort(all(aa));
		reverse(all(aa));
		vector<vi> res(n, vi(4, 0));
		for(int i = n +1, j = 0; i > 0; --i){
			if(aa[i].first == 0){
				continue;
			}else{
				res[j][0] = aa[i].second; 
				res[j][1] = min(aa[i].first, k);
				aa[i].first -= min(aa[i].first, k);
				++j;
			}
		}
		for(int i = 0, j = 0; i <= n; ++i){
			while(aa[i].first > 0 and j < n){
				if(res[j][1] == 0){
					res[j][0] = aa[i].second;
					res[j][1] = min(k, aa[i].first);
					aa[i].first -= min(k, aa[i].first);
				}else if(res[j][1] < k){
					if(res[j][0] == aa[i].second){
						int temp = min(k - res[j][1], aa[i].first);
						res[j][1] += temp;
						aa[i].first -= temp;
					}else{
						res[j][2] = aa[i].second;
						res[j][3] = min(k - res[j][1], aa[i].first);
						aa[i].first -= min(k - res[j][1], aa[i].first);
					}
				}
				if(res[j][3] != 0 or res[j][1] + res[j][3] == k){
					++j;
				}
			}
		}
		for(auto itr: res){
			for(auto it: itr)
				cout << it << " ";
			cout << endl;
		}
	// }



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
