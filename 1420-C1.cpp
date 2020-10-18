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
	int n, q, ans = 0, l, r;
	cin >> n >> q;
	vi a(n), b, c;
	scnarr(a, n);

	if(n == 1 or n == 2){
		cout << (*max_element(all(a))) << endl;
		while(q--){
			cin >> l >> r;
			cout << (*max_element(all(a))) << endl;
		}
		cout << endl;
		return;
	}
	
	int cnt = 1;

	for(int i = 0; i < n; ++i){
		if(i == 0 and a[i] > a[i +1] and cnt&1){
			b.push_back(a[i]);
			cnt++;
		}else if(i == n -1 and a[i] > a[i -1] and cnt&1){
			b.push_back(a[i]);
			cnt++;
		}else if(a[i] > a[i +1] and a[i] > a[i -1] and cnt&1){
			b.push_back(a[i]);
			cnt++;
		}else if(a[i] < a[i +1] and a[i] < a[i -1] and cnt%2==0){
			b.push_back(a[i]);
			cnt++;
		}
	}

	if(b.size()&1){
		for(int i = 0; i < b.size(); ++i){
			if(i&1){
				ans += -b[i];
			}else{
				ans += b[i];
			}
		}
	}else{
		int ans1 = 0, ans2 = 0;
		for(int i = 0; i < b.size() -1; ++i){
			if(i&1){
				ans1 += -b[i];
			}else{
				ans1 += b[i];
			}
		}
		for(int i = 1; i < b.size(); ++i){
			if(i&1){
				ans2 += -b[i];
			}else{
				ans2 += b[i];
			}
		}
		ans = max(ans1, ans2);
	}

	cout << ans << endl;

	while(q--){
		cin >> l >> r;
		--l, --r;
		int tempL = a[l], tempR = a[r];
		a[l] = tempR;
		a[r] = tempL;
		if(l == r){
			cout << ans << endl;
		}else{
			if(l == 0){
				if(tempL > a[l +1]){
					ans -= tempL;
				}
				if(a[l] > a[l +1]){
					ans += a[l];
				}
			}else{
				if(a[l] > a[l +1] and  a[l] > a[l -1]){
					ans += a[l];
				}
				if(tempL > a[l +1] and tempL > a[l -1]){
					ans -= tempL;
				}
			}
			if(r == n -1){
				if(tempR > a[r -1]){
					ans -= tempR;
				}
				if(a[r] > a[r -1]){
					ans += a[r];
				}	
			}else{
				if(a[r] > a[r -1] and a[r] > a[r +1]){
					ans += a[r];
				}
				if(tempR > a[r -1] and tempR > a[r +1]){
					ans -= tempR;
				}
			}

			cout << ans << endl;

		}
	}
	cout << endl;
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
	