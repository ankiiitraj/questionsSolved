#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
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
const int MAXN = 10005; // 1e4 +5
const int INF = 100000000000005; // 1e15 +5

vi sizes(MAXN), head(MAXN);

void init(int n){
	for(int i = 1; i <= n; ++i){
		sizes[i] = 1;
		head[i] = i;
	}
}

int findHead(int x){
	if(head[x] == x) return x;

	return head[x] = findHead(head[x]);
}

void _union(int x, int y){
	if(sizes[x] < sizes[y]) swap(x, y);
	int headX = findHead(x), headY = findHead(y);
	sizes[headX] += sizes[y];
	head[y] = headX;
	sizes[y] = 0;

	return;
}

void solve(){
	int n;
	cin >> n;
	vi a(n +1);
	scnarr(a, n);
	head = sizes = vi(n +2);
	init(n);
	int p, x, y;
	cin >> p;
	for(int i = 0; i < p; ++i){
		cin >> x >> y;
		if(findHead(x) != findHead(y)){
			_union(x, y);
		}
	}
	unordered_map<int, int> m, mh;
	for(int i = 1; i <= n; ++i){
		findHead(i);
		m[head[i]] += a[i];
		mh[head[i]]++;
	}
	// debug(head, m, mh);
	int _max = 0, _min = INT_MAX, resHead;
	for(auto itr: m){
		if(itr.second > _max){
			_max = itr.second;
			_min = mh[itr.first];
			resHead = itr.first;
		}else if(itr.second == _max and mh[itr.first] < _min){
			_min = mh[itr.first];
			resHead = itr.first;
		}
	}

	vi res;
	for(int i = 1; i <= n; ++i){
		if(head[i] == resHead) cout << i << " ";
	}


	return;
}

signed main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
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
