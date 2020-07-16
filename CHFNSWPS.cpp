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
		long long n, temp, cnt = 0; 
		scanf("%lld", &n);
		vector<long long> d;
		map<long long, long long> m, c, aa, bb;
		for(long long i = 0; i < 2*n; ++i) {
			scanf("%lld", &temp);
			if(i < n)
				aa[temp]++;
			else
				bb[temp]++;
			m[temp]++;
		}
		for(auto &itr: m) {
			cnt += itr.second/2;

			c[itr.first] = itr.second/2;
		}

		if(cnt != n) {
			printf("-1\n");
		} else {
			for(auto &itr: c){
				if(itr.second > aa[itr.first]){
					long long i = 0;
					while(i < itr.second - aa[itr.first])
					d.push_back(itr.first), ++i;
				}
				if(itr.second > bb[itr.first]){
					long long i = 0;
					while(i < itr.second - bb[itr.first])
					d.push_back(itr.first), ++i;
				}
			}
			sort(d.begin(), d.end());

			long long _min = min(aa.begin()->first, bb.begin()->first), ans = 0;

			for(long long i = 0; i < d.size()/2; ++i){
				if(2*_min < d[i]){
					ans += 2*_min;
				}else{
					ans += d[i];
				}
			}
			printf("%lld\n", ans);
		}

	}
}