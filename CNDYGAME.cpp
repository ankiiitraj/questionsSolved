#include <bits/stdc++.h>
#include <time.h>
#define int long long int
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
const int INF = 100000000000005; // 1e15 +5

void solve(){
	int n, q, r, cnt = 0, sum = 0;
	cin >> n;
	vi a(n), pref(n), ferp(n, 0);
	scnarr(a, n);

	if(n == 1){
		cin >> q;
		while(q--){
			cin >> r;
			cout << ((a[0] - (!(a[0]&1))) * r) << endl;
		}
		return;
	}

	bool flag = (a[0] == 1);
	sum += a[0];
	pref[0] = a[0] - (a[0]&1) + flag;
	cnt += flag;
	for(int i = 1; i < n -1; ++i){
		if(a[i] == 1 and !flag){
			sum += 1;
			ferp[i] = ferp[i -1];
			pref[i] = pref[i -1] +1;
			flag = 1;
			cnt++;
		}else if(a[i] > 1 and !flag){
			ferp[i] = ferp[i -1];
			pref[i] = pref[i -1] + a[i] - (a[i]&1); 
			sum += a[i] - (a[i]&1);
		}else if(a[i] == 1 and flag){
			flag = 0;
			cnt++;
			ferp[i] = ferp[i -1] +1;
			pref[i] = pref[i -1];
			sum += 1;
		}else{
			sum += a[i] - (a[i]&1);
			ferp[i] = ferp[i -1] + a[i] - (a[i]&1);
			pref[i] = pref[i -1];
		}
	}
	if(!flag){
		pref[n -1] = pref[n -2] + a[n -1] - (!(a[n -1]&1));
		ferp[n -1] = ferp[n -2];
	}else{
		ferp[n -1] = ferp[n -2] + a[n -1] - (!(a[n -1]&1));
		pref[n -1] = pref[n -2];
	}
	sum += a[n -1] - (!(a[n -1]&1));

	cin >> q;
	while(q--){
		cin >> r;

		if(cnt%2 == 0){
			cout << (pref[n -1] * (int)(r/n) + (r % n != 0 ? pref[r % n -1] : 0)) << endl;
		}else{
			int res = sum * (int)((r / n)/2);
			if((int)((r / n) % 2) == 0){
				if(r % n != 0){
					res += pref[r % n -1];
				}
			}else{
				res += pref[n -1];
				if(r % n != 0){
					res += ferp[r % n -1];
				}
			}
			cout << res << endl;
		}
	}

	return;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
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
