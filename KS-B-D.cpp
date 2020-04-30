#include <bits/stdc++.h>
#define int long long int
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

int numberOfPaths(int m, int n) 
{ 
    int path = 1; 
    for (int i = n; i < (m + n - 1); i++) { 
        path *= i; 
        path /= (i - n + 1); 
    } 
    return path; 
} 


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; for(int test = 1; test <= t; ++test)
	{
		int  w, h, l, u, r, d, sum = 0;
		cin >> w >> h >> l >> u >> r >> d;
		vi paths;
		for(int i = 0; i < r - l +1; ++i){
			if(i == 0)
				paths.push_back(numberOfPaths(l, u));
			else
				paths.push_back(paths[paths.size() -1] - numberOfPaths(l +i, u));
		} 
		for(int i = 0; i < d - u +1; ++i){
			if(i == 0)
				paths.push_back(numberOfPaths(l, u));
			else
				paths.push_back(paths[paths.size() -1] - numberOfPaths(l, u + i));
		} 
		for(int i = 0; i < paths.size(); ++i){
			sum += paths[i];
		}
		long double ans;
		if(r == w and d == h){
			sum -= 2;
		}else if(r == w){
			sum--;
		}else if(d == h){
			sum--;
		}

		ans = sum/((numberOfPaths(w, h) - sum));

		cout << "Case #" << test << ": " << fixed << setprecision(12) << 1 - ans << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	