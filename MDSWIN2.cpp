#include <bits/stdc++.h>
#define int long long int
#define len length
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 998244353;
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

int n;

/*	Call init_fact() in MAIN
	Use "power" function
*/
int fact[100005];	//1e5 + 5
void init_fact() {
    fact[0] = 1;
    for(int i=1;i<100005;i++)   fact[i] = (fact[i-1]*i)%MOD;
}
int modInverse(int n)	{ int res = power(n,MOD-2); return res; }	//only if MOD is prime
int nCr(int n, int r) {
    if(r==0)    return 1LL;
    return (fact[n]*modInverse((fact[r]*fact[n-r])%MOD))%MOD;
}


int32_t main()
{
	init_fact();
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int q, l, r, ans;
		cin >> n;
		scnarr(a, n);
		cin >> q;
		while(q--){
			cin >> l >> r;
			--l, --r;
			mii m;
			for (int i = l; i <= r; ++i)
				m[a[i]]++;
			if(m.size() == 2){
				if(m.begin().second == (++m.begin()).second)
					cout << "0\n";
				else
					cout << nCr(max(m.begin().second, (++m.begin()).second), abs(m.begin().second - (++m.begin()).second))%MOD << endl;
			}else{
				int sumOfPowers = 0;
				for(auto &itr:m){
					sumOfPowers += itr.second;
				}
				
			}	
		}

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
