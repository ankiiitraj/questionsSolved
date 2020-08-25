#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define ld double
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
const int INF = 10000000005; // 1e15 +5

struct point{
	int x, y, id;
};

bool cmp(point &p1, point &p2){
	if(p1.x == p2.x)
		return p1.y < p2.y;
	return p1.x < p2.x;
}

ld dist(point p1, point p2){ 
	return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}

pair<ld, pii> bruteForce(vector<point> a, int n){
    ld min_ = INF*1.0;
    pair<ld, pii> res;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if (dist(a[i], a[j]) < min_){
                min_ = dist(a[i], a[j]);
                res = {min_, {a[i].id, a[j].id}};
            }
        }
    }
    return res;
}

pair<ld, pii> divide_and_conquer(vector<point> &a, int l, int r){
	if(r - l +1 <= 3){
		vector<point> temp;
		for(int i = l; i <= r; ++i){
			temp.push_back(a[i]);
		}
		return bruteForce(temp, temp.size());
	}

	int mid = l + (r - l)/2;
	point p1, p2, mid_p = a[mid];

	pair<ld, pii> ll = divide_and_conquer(a, l, mid), lr = divide_and_conquer(a, mid +1, r);
	int min_dist = min(ll.first, lr.first);
	vector<point> temp;

	for(int i = l; i <= r; ++i){
		if(abs(a[i].x - mid_p.x) < min_dist){
			temp.push_back(a[i]);
		}
	}

	return bruteForce(temp, temp.size());
	

}

void solve(){
	cout << fixed << setprecision(9);
	int n;
	cin >> n;
	vector<point> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	
	sort(all(a), cmp);

	pair<ld, pii> ans = divide_and_conquer(a, 0, n -1);

	cout << ans.second.first << " " << ans.second.second << " " << ans.first << endl;

	return;
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
	