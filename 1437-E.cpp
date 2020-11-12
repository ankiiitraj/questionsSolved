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
	int n, k;
	cin >> n >> k;
	vi a(n), b(k);
	scnarr(a, n);
	scnarr(b, k);
	for(auto &itr: b)
		itr--;

	auto lis = [&](vi v){
		if(v.empty())
			return 0LL;
		int res = 1;
		vi temp = v;

		multiset <int> s;
		multiset <int> :: iterator it;

		for(int i = 0; i < temp.size(); ++i){
		    s.insert(temp[i]);
		    
		    it = s.upper_bound(temp[i]);
		    
		    if(it != s.end())
		        s.erase(it);
		}
		return (int)s.size();
	};
	if(k == 0){
		for(int i = 0; i < n; ++i)
			a[i] = a[i] - i;
		int res = lis(a);
		cout << n - res << endl;
		return;
	}

	vi left(n), right(n), marked(n, 0);
	for(int i = 0; i < b[0]; ++i){
		right[i] = b[0];
		
		if(a[i] > a[right[i]] - (-i + right[i])){
			marked[i] = 1;
		}
	}
	for(int i = 1; i < k; ++i){
		if(a[b[i]] - a[b[i -1]] < b[i] - b[i -1]){
			cout << "-1\n";
			return;
		}
		for(int j = b[i -1] +1; j < b[i]; ++j){
			left[j] = b[i -1];
			right[j] = b[i];
			if((a[j] < a[left[j]] + j - left[j]) or (a[j] > a[right[j]] - (-j + right[j]))){
				marked[j] = 1;
			}
		}
	}
	for(int i = b[k -1]; i < n; ++i){
		left[i] = b[k -1];
		if(a[i] < a[left[i]] + i - left[i]){
			marked[i] = 1;
		}
	}
	
	int res = 0, prev = b[0];
	vi tmp;
	for(int i = 0; i <= b[0]; ++i){
		if(!marked[i])
			tmp.push_back(a[i] - i);
	}
	res += lis(tmp) -1;
	for(int i = 1; i < k; ++i){
		vi temp;
		for(int j = prev; j <= b[i]; ++j){
			if(!marked[j]){
				temp.push_back(a[j] - j);
			}
		}
		res += lis(temp) -2;
		prev = b[i];
	}

	vi temp;
	for(int i = prev; i < n; ++i){
		if(!marked[i]){
			temp.push_back(a[i] - i);
		}
	}
	res += lis(temp) -1;
	res += k;
	cout << n - res << endl;
	return;
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
