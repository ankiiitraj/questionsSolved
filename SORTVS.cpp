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


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, m, x, y, cnt = 0;
		cin >> n >> m;
		vi a(n), b(n), res(n);
		set<pii> s;
		mii saved;

		for(int i = 0; i < n; ++i){
			cin >> a[i];
			a[i]--;
			b[i] = i;
			saved[i] = i;
		}
		for(int i = 0; i < m; ++i){
			cin >> x >> y;
			--x, --y;
			s.insert({x, y});
			s.insert({y, x});
		}

		for(int i = 0; i < n; ++i){
			res[a[i]] = i;
		}
		// debug(s);

		for(int i = 0; i < n; ++i){
			if(b[i] != res[i]){
				int temp = b[i];
				b[i] = res[i];
				b[saved[res[i]]] = temp;
				if(s.find({i, saved[res[i]]}) == s.end() and s.find({saved[res[i]], i}) == s.end())
					cnt++;
				saved[temp] = saved[res[i]];
				saved[res[i]] = i;
				// debug(b, saved);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	