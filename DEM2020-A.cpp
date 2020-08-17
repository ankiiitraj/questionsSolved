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
vi primes;
int MAX = 1000006;
void sieve() 
{ 
    bool isComposite[MAX] = {false}; 
    for (int i=2; i*i<=MAX; i++) 
    { 
        if (isComposite[i]==false) 
            for (int j=2; j*i<=MAX; j++) 
                isComposite[i*j] = true; 
    } 
  
    for (int i=2; i<=MAX; i++) 
        if (isComposite[i]==false) 
            primes.push_back(i); 
} 
  
int LCM(int n) 
{ 
    int lcm = 0;
    int idx = lower_bound(all(primes), n) - primes.begin();
    if(primes[idx] > n){
    	idx--;
    }
    for (int i = idx; i >= 0; i--) 
    { 
        int pp = primes[i]; 
        while (pp*primes[i] <= n) 
            pp = pp *primes[i]; 
  
        lcm++;
    } 
    return lcm; 
} 

void solve(){
	int n;
	cin >> n;
	if(n < 2)
		cout << "0\n";
	else if(n == 2)
		cout << "1\n";
	else{
		int ans = LCM(n);
		ans = ans > 2 ? ans -1: ans;
		ans++;
		cout << ans + n -4 << endl;
	}
	
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	sieve();

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
	