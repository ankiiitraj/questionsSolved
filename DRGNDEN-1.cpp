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
const int MAXN = 200005; // 1e6 +5

/*1-Based indexing*/
vi max_tree(4*MAXN, -1);
void build(vi &a, int l, int r, int root){
	if(l == r){
		max_tree[root] = a[l];
		return;
	}
	build(a, l, (l + r)/2, 2*root);
	build(a, (l + r)/2 +1, r, 2*root +1);
	max_tree[root] = max(max_tree[2*root], max_tree[2*root +1]);
}
int max_query(int ql, int qr, int l, int r, int root){
	if(ql <= l and qr >= r)
		return max_tree[root];
	if(ql > r or qr < l)
		return 0;
	return max((int)max_query(ql, qr, l, (l + r)/2, 2*root), (int)max_query(ql, qr, (l + r)/2 +1, r, 2*root +1));
}

/*1-Based indexing*/
pair<int, si> tree(4*MAXN, -1), rtree(4*MAXN, -1);
void build(vi &tree, vi &a, vi &b, int l, int r, int root){
	if(l == r){
		tree[root] = b[l];
		return;
	}
	build(tree, a, b, l, (l + r)/2, 2*root);
	build(tree, a, b, (l + r)/2 +1, r, 2*root +1);

	int res = b[l], prev = a[l];
	for(long long i = l +1; i <= r; ++i){
		if(a[i] > prev){
			res += b[i];
		}
	}
	tree[root] = res;
}
int nct = 0;
int query(vi &tree, vi &nearest_greater, int ql, int qr, int l, int r, int n, int root){
	// debug(ql, qr, l, r);
	if(l > qr or r < ql or nct == 10)
		return 0;
	if(ql > qr)
		return 0;
	if(ql == qr and l == ql and r == ql)
		return tree[root];
	// nct++;
	if(l == ql and qr >= r){
		// debug(ql, qr, l, r, '-');
		return tree[root] + query(tree, nearest_greater, nearest_greater[r], qr, 1, n, n, 1);
	}
	
	int one = query(tree, nearest_greater, ql, qr, l, (l + r)/2, n, 2*root);
	if(one == 0)
		one += query(tree, nearest_greater, ql, qr, (l + r)/2 +1, r, n, 2*root +1);
	return one;

}

void update(vi &tree, int pos, int val, int l, int r, int root, vi &a, vi &b){
	if(pos < l or pos > r)
		return;
	if(l == r and l == pos){
		a[l] = val;
		tree[root] = a[l];
		return;
	}

	update(tree, pos, val, l, (l + r)/2, 2*root, a, b);
	update(tree, pos, val, (l + r)/2 +1, r, 2*root +1, a, b);
	tree[root] = tree[2*root] + tree[2*root +1];
}


void solve(){
	int n, q, ty, x, y;
	cin >> n >> q;
	vi a(n +1), b(n +1), ra(n +1);
	{
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
			ra[i] = -a[i];
		}
		for(int i = 1; i <= n; ++i){
			cin >> b[i];
		} 
	}

	rtree.resize(4*n +5);
	tree.resize(4*n +5);
	build(rtree, a, b, 1, n, 1);
	build(tree, ra, b, 1, n, 1);
	build(a, 1, n, 1);

	vi r_nearest_greater(n +1), nearest_greater(n +1);
	stack<long long> temp;
	for(int i = 1; i <= n; ++i){
		r_nearest_greater[i] = i;
		while(!temp.empty() and a[temp.top()] < a[i]){
			r_nearest_greater[temp.top()] = i;
			temp.pop();
		}
		temp.push(i);
	}
	stack<long long> rtemp;
	for(int i = 1; i <= n; ++i){
		nearest_greater[i] = i;
		while(!rtemp.empty() and ra[rtemp.top()] < ra[i]){
			nearest_greater[rtemp.top()] = i;
			rtemp.pop();
		}
		rtemp.push(i);
	}

	// debug(rtree, r_nearest_greater);
	// debug(tree, nearest_greater);

	while(q--){
		cin >> ty >> x >> y;
		if(ty == 1){
			b[x] = y;
		}else{
			if(x == y)
				cout << b[x] << endl;
			else{
				if(x > y){
					if(a[x] <= a[y]){
						printf("-1\n");
						continue;
					}
					int max_elem = max_query(y +1, x -1, 1, n, 1);
					if(max_elem >= a[x]){
						cout << "-1\n";
						continue; 
					}
					cout << query(rtree, r_nearest_greater, y, x, 1, n, n, 1) << endl;
				}
				else{
					// cout << "-1\n";
					if(a[x] <= a[y]){
						printf("-1\n");
						continue;
					}
					int max_elem = max_query(x +1, y -1, 1, n, 1);
					if(max_elem >= a[x]){
						cout << "-1\n";
						continue; 
					}
					cout << query(tree, nearest_greater, x, y, 1, n, n, 1) << endl;
				}
				nct = 0;
			}
		}
		// debug("---");
	}


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
	