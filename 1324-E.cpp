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
vi a;
int memo[2005][2005];
int n, h, l, r;
int count(int ind, int time){
	// cout << time <<endl;
	if(ind == n){
		return 0;
	}
	if(memo[ind][time] != -1)
		return memo[ind][time];

	int taken, notTaken;
	
	if(((time + a[ind])%h >= l and (time + a[ind])%h <= r))
		notTaken = count(ind +1, (time + a[ind])%h) +1;
	else
		notTaken = count(ind +1, (time + a[ind])%h);
	
	if(((time + a[ind] -1)%h >= l and (time + a[ind] -1)%h <= r))	
		taken = count(ind +1, (time + a[ind] -1)%h) +1;
	else
		taken = count(ind +1, (time + a[ind] -1)%h);
	
	memo[ind][time] = max(taken, notTaken);

	return memo[ind][time];
}

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		memset(memo, -1, sizeof(memo));
		cin >> n >> h >> l >> r;
		a.resize(n);
		scnarr(a, n);
		cout << count(0, 0) << "\n";
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
