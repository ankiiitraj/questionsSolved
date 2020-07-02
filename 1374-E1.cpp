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

struct tup{
	int t, a, b;
};

bool cmp(tup &t1, tup &t2){
	return t1.t < t2.t;
}

void solve(){
	int n, k, cnt_a = 0, cnt_b = 0;
	cin >> n >> k;
	vector<tup> a(n);

	for(int i = 0; i < n; ++i){
		cin >> a[i].t >> a[i].a >> a[i].b;
		if(a[i].a)
			cnt_a++;
		if(a[i].b)
			cnt_b++;
	}
	if(cnt_b < k or cnt_a < k){
		cout << -1 << endl;
		return;
	}

	vector<tup> both, a_only, b_only;
	sort(all(a), cmp);

	for(auto itr: a){
		if(itr.a and itr.b){
			both.push_back(itr);
		}else if(itr.a){
			a_only.push_back(itr);
		}else if(itr.b){
			b_only.push_back(itr);
		}
	}

	int i = 0, ans = 0;

	while(i < min(a_only.size(), b_only.size())){
		both.push_back({a_only[i].t + b_only[i].t, 1, 1});
		++i;
	}

	sort(all(both), cmp);
	i = 0;
	for(auto itr: both){
		if(i >= k){
			break;
		}
		ans += itr.t;
		i++;
	}

	cout << ans << endl;

}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
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