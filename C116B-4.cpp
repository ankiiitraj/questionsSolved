#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5
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


vi treeMax, treeMin, a, aMax, aMin;
// pass l = 0, r = n -1, 0based indexing
void buildMin(int root, int l, int r){
	if(l == r){
		treeMin[root] = aMin[l];
		return;
	}
	int mid = (l + r)/2;
	buildMin(2*root, l, mid);
	buildMin(2*root +1, mid +1, r);
	treeMin[root] = min(treeMin[2*root], treeMin[2*root +1]);
} 
void buildMax(int root, int l, int r){
	if(l == r){
		treeMax[root] = aMax[l];
		return;
	}
	int mid = (l + r)/2;
	buildMax(2*root, l, mid);
	buildMax(2*root +1, mid +1, r);
	treeMax[root] = max(treeMax[2*root], treeMax[2*root +1]);
} 
void updateMin(int root, int l, int r, int idx, int val){
	if(l > idx or r < idx)
		return;
	if(l == r){
		aMin[idx] = val;
		treeMin[root] = val;
		return;
	}
	int mid = (l + r)/2;

	updateMin(2*root, l, mid, idx, val);
	updateMin(2*root +1, mid +1, r, idx, val);

	treeMin[root] = min(treeMin[2*root], treeMin[2*root +1]);
}
void updateMax(int root, int l, int r, int idx, int val){
	if(l > idx or r < idx)
		return;
	if(l == r){
		aMax[idx] = val;
		treeMax[root] = val;
		return;
	}
	int mid = (l + r)/2;

	updateMax(2*root, l, mid, idx, val);
	updateMax(2*root +1, mid +1, r, idx, val);

	treeMax[root] = max(treeMax[2*root], treeMax[2*root +1]);
}

int queryMin(int root, int l, int r, int ql, int qr){
	if(r < ql or l > qr){
		return 100000000000;
	}
	if(l >= ql and r <= qr)
		return treeMin[root];
	int mid = (l + r)/2;
	return min(queryMin(2*root, l, mid, ql, qr), queryMin(2*root +1, mid +1, r, ql ,qr));
}
int queryMax(int root, int l, int r, int ql, int qr){
	if(r < ql or l > qr){
		return -100000000000;
	}
	if(l >= ql and r <= qr)
		return treeMax[root];
	int mid = (l + r)/2;
	return max(queryMax(2*root, l, mid, ql, qr), queryMax(2*root +1, mid +1, r, ql ,qr));
}



int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, q, res = 0, l, r;
		char ty;
		cin >> n >> q;
		a.resize(n);
		scnarr(a, n);
		aMax = a, aMin = a;


		
		treeMax.resize(4*n +1, -1000000000000);
		treeMin.resize(4*n +1, 100000000000);
		
		for(int i = 1; i < n; ++i)
			aMax[i] += aMax[i -1];
		
		aMin = aMax;

		buildMax(1, 0, n -1);
		buildMin(1, 0, n -1);

		while(q--){
			cin >> ty >> l >> r;
			--l, --r;
			if(ty == 'U'){
				updateMax(1, 0, n -1, l, r);
				updateMin(1, 0, n -1, l, r);
			}else{
				if(l == 0){
					cout << queryMax(1, 0, n -1, r, n -1) << endl;
					continue;
				}
				cout << queryMax(1, 0, n -1, r, n -1) - queryMin(1, 0, n -1, 0, l -1) << endl;
			}
		}


		// cout << res << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	