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

/*1-Based indexing*/
vi tree(4*MAXN, -1);
void build(vi &a, int l, int r, int root){
	if(l == r){
		if(a[l]&1)
			tree[root] = 1;
		else
			tree[root] = 0;
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
void update(int pos, int val, int l, int r, int root, vi &a){
	if(pos < l or pos > r)
		return;
	if(l == r and l == pos){
		int temp = a[l];
		a[l] = val;
		if(a[l]&1 and temp%2 == 0)
			tree[root]++;
		else if(a[l]%2 == 0 and temp&1)
			tree[root]--;
		return;
	}

	update(pos, val, l, (l + r)/2, 2*root, a);
	update(pos, val, (l + r)/2 +1, r, 2*root +1, a);
	tree[root] = tree[2*root] + tree[2*root +1];
}


void solve(){
	int n, q, l, r, ty;
	cin >> n;
	vi a(n +1);
	scnarr(a, n);

	build(a, 1, n, 1);

	cin >> q;
	while(q--){
		cin >> ty >> l >> r;
		if(ty == 0){
			update(l, r, 1, n, 1, a);
		}else if(ty == 1){
			cout << r - l +1 - query(l, r, 1, n, 1) << endl;
		}else{
			cout << query(l, r, 1, n, 1) << endl;
		}
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
	