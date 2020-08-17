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
/*
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
const int INF = 100000000000005; // 1e15 +5

vi solve(vi &a){
	vi minmax;
	if(a[0] > a[1]){
		minmax.push_back(a[0]);
	}

	for(int i = 1; i < a.size() -1; ++i){
		if((a[i] > a[i +1] and a[i] > a[i -1]) or (a[i] > a[i +1] and a[i] > a[i -1])){
			minmax.push_back(a[i]);
		}else if((a[i] < a[i +1] and a[i] < a[i -1]) or (a[i] < a[i +1] and a[i] < a[i -1])){
			minmax.push_back(a[i]);
		}
	}
	return minmax;
}

vi remove_dupilicates(vi &a){
	vi temp;
	for(int i = 0; i < a.size(); ++i){
		int idx = i;
		while(a[idx] == a[idx +1]){
			idx++;
		}
		temp.push_back(a[i]);
		i = idx;
	}
	if(temp.back() != a[a.size() -1]){
		temp.push_back(a[a.size() -1]);
	}
	return temp;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--){

		int n, ans = 0;
		cin >> n;
		vi a(n), minmax, temp;
		scnarr(a, n);

		if(n == 1){
			cout << 0 << endl;
			continue;
		}

		
		a = remove_dupilicates(a);
		minmax = solve(a);
		
		if(a[n -1] < a[n -2]){
			minmax.push_back(a[n -1]);
		}

		while(!minmax.empty()){
			vi new_minmax;
			int flag = 0;
			for(int i = 0; i < minmax.size() -1; ++i){
				if(minmax[i] > minmax[i +1]){
					flag = 1;
					break;
				}
			}
			if(!flag)
				break;
			for(int i = 1; i < minmax.size(); i += 2){
				if(i == minmax.size() -1){
					ans += minmax[i -1] - minmax[i];
					new_minmax.push_back(minmax[i -1]);
				}
				else{
					ans += min(minmax[i -1], minmax[i +1]) - minmax[i];
					new_minmax.push_back(minmax[i -1]);
				}
			}
			new_minmax = remove_dupilicates(new_minmax);
			minmax = solve(new_minmax);
			// debug(minmax, ans);
		}

		cout << ans << endl;
	}
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
