#include<bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
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

const long long mod = 998244353;

long long power(long long x, long long y){
	long long ans = 1;
	while(y > 0){
		if(y&1){
			ans = (ans * x)%mod;
			--y;
		}else{
			x = (x * x)%mod;
			y /= 2;
		}
	}
	return ans % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for(int test = 0; test < t; ++test)
	{
		long long int n, x, a;
		cin >> n >> x;

		for(long long int i = 0; i < n; ++i)
			cin >> a;

		long long gp[n +1] = {0}, res = 1;
			
		for(int i = 1; i <= n; ++i){
			gp[i] = (gp[i -1] + power(x, i -1)) % mod;

		}


		for(int i = 1; i <= n; ++i){
			long long cur = a * gp[n - i +1] % mod;
			cur = cur * cur % mod;

			res = res * power(cur, i) % mod;

		}

		cout << res % mod << endl;

	}
}