#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353; // 1e9 + 7
const int N = 1000001; // 1e6 +1
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
int n, w, x, y, memo[1005][1005][2][2];
int valX[2], valY[2];
vi weights(1005), val(1005);

int knapSack(int ind, int wt, int x, int y){
	if(wt <= 0 or ind >= n){
		return 0;
	}
	if(memo[ind][wt][x][y] != -1){
		return memo[ind][wt][x][y];
	}
	if(wt - weights[ind] >= 0){
		memo[ind][wt][x][y] = max({knapSack(ind +1, wt, x, y) + 0, knapSack(ind +1, wt - weights[ind], x, y) + val[ind], knapSack(ind +1, wt - weights[ind], 0, y) + val[ind]*valX[x], knapSack(ind +1, wt - weights[ind], x, 0) + val[ind]*valY[y]});
	}else{
		memo[ind][wt][x][y] = knapSack(ind +1, wt, x, y);
	}

	return memo[ind][wt][x][y];
}
// 16
// -1 -1 -1 -1 -1 16 
// -1 -1 -1 -1 6 14 
// -1 -1 0 6 6 12 
// 20
// -1 -1 -1 -1 -1 20 
// -1 -1 -1 -1 12 16 
// -1 -1 0 12 12 12 



int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		cin >> n >> w >> x >> y;
		memset(memo, -1, sizeof(memo));
		weights.resize(n);
		val.resize(n);
		valX[0] = 1, valX[1] = x, valY[0] = 1, valY[1] = y;
		scnarr(weights, n);
		scnarr(val, n);
		cout << knapSack(0, w, 1, 1) << endl;

		// for (int i = 0; i < n; ++i){
		// 	for(int j = 0; j <= w; ++j)
		// 		cout << memo[i][j] << " ";
		// 	cout << endl;
		// }

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
