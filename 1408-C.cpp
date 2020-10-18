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
	cout << fixed << setprecision(10);
	int n, l;
	cin >> n >> l;
	vi a(n);
	scnarr(a, n);
	
	double left = 0.0, right = l*1.0; int l_speed = 1, r_speed = 1, l_idx = 0, r_idx = n -1;
	double time = 0.0;
	while(left < right){
		if(l_idx <= r_idx){
			if((double)(((right - a[r_idx])*1.0)/(r_speed*1.0)) < (double)(((-left + a[l_idx])*1.0)/(l_speed*1.0))){
				left = left + (l_speed * 1.0 * ((double)(((right - a[r_idx])*1.0)/(r_speed*1.0))));
				time += (double)(((right - a[r_idx])*1.0)/(r_speed*1.0));
				right = a[r_idx--];
				r_speed++;
			}else if((double)((right - a[r_idx])/r_speed) > (double)((-left + a[l_idx])/l_speed)){
				right = right - (double)(r_speed*1.0 * ((double)(((-left + a[l_idx])*1.0)/(l_speed*1.0))));
				time += (double)(((-left + a[l_idx])*1.0)/(l_speed*1.0));
				left = a[l_idx++];
				l_speed++;
			}else{
				time += (double)(((-left + a[l_idx])*1.0)/(l_speed*1.0));
				r_speed++;
				l_speed++;
				right = a[r_idx--];
				left = a[l_idx++];
			}
		}else{
			time = time + (double)(abs((left - right)*1.0)/((l_speed + r_speed)*1.0));
			cout << time << endl;
			return;
		}
	}
	cout << time << endl;
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
	