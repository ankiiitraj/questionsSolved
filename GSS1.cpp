#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
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
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

struct node{
	int sum, prefix, suffix;
};

int power(int x, int y){
	int ans = 1;
	while(y > 0){
		if(y&1){
			ans = (ans * x)%MOD;
			--y;
		}else{
			x = (x * x)%MOD;
			y /= 2;
		}
	}
	return ans;
}

node kadeanes_pre_suf(vi &a, int l, int r){
	node res;
	int cur = 0, tot = -MOD, pre = 0, suf = 0;
	for(int i = l; i <= r; ++i){
		cur += a[i];
		if(cur < 0){
			cur = 0;
		}
		tot = max(tot, cur);
	}
	res.sum = tot;
	tot = -MOD, cur = 0;
	for(int i = l; i <= r; ++i){
		cur += a[i];
		tot = max(tot, cur);
	}
	res.prefix = tot > 0 ? tot : 0;
	
	tot = -MOD, cur = 0;
	for(int i = r; i >= l; --i){
		cur += a[i];
		tot = max(tot, cur);
	}
	res.suffix = tot > 0 ? tot : 0;

	return res;
}

/*1-Based indexing*/
vector<node> tree(4*MAXN, -1);
void build(vi &a, int l, int r, int root){
	if(l == r){
		tree[root].sum = a[l];
		a[l] > 0 ? tree[root].prefix = tree[root].suffix = a[l] : tree[root].prefix = tree[root].suffix = 0;
		return;
	}
	build(a, l, (l + r)/2, 2*root);
	build(a, (l + r)/2 +1, r, 2*root +1);
	tree[root] = tree[2*root] + tree[2*root +1];
}
int query(int ql, int qr, int l, int r, int root){
	if(ql <= l and qr >= r)
		return tree[root];
	if(ql > r or qr < l)
		return 0;
	return (query(ql, qr, l, (l + r)/2, 2*root) + query(ql, qr, (l + r)/2 +1, r, 2*root +1));
}

void solve(){
	int n, m, l, r;
	cin >> n;
	vi a(n +1);
	scnarr(a, n);

	cin >> m;
	while(m--){
		cin >> l >> r;
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
	