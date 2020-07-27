#include<bits/stdc++.h>
#define int long long 
using namespace std;
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

int power(int x, int y, int m){
	int res = 1;
	while(y){
		if(y&1)
			res = (res * x) % m, --y;
		else
			x = (x * x) % m, y /= 2;
	}
	return res;
}
const int MAXN = 1000005;
vector<int> spf(MAXN, 0);

void sieve(){
	for(int i = 1; i < MAXN; ++i)
		spf[i] = i;
	for(int i = 2; i*i < MAXN; ++i){
		if(spf[i] == i){
			for(int j = i*i; j < MAXN; j += i){
				if(spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

map<int, int> prime_factorizaion(int x){
	map<int, int> res;
	while(x != 1){
		res[spf[x]]++;
		x /= spf[x];
	}
	return res;
}


signed main(){
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	sieve();
	int t; scanf("%lld", &t); while(t--){
		int n, m, k;
		scanf("%lld%lld%lld", &n, &m, &k);
		int a, l = 1;
		map<int, int> lcm;

		for(int i = 0; i < n; ++i){
			cin >> a;
			if(a != 1){
				map<int, int> temp = prime_factorizaion(a);
				for(auto itr: temp){
					if(itr.second != 0)
						lcm[itr.first] = max(itr.second, lcm[itr.first]);
				}
			}
		}

		for(auto itr: lcm){
			l = l * power(itr.first, itr.second, m) % m;
			if(l == 0)
				break;
		}

		l = power(l, k, m);
		printf("%lld\n", l);
	}
}