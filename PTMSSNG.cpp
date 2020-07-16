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

struct point{
	long long x, y;
};

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
		long long n, x, y; 
		scanf("%lld", &n);
		vector<point> points;
		map<long long, long long> x_axis, y_axis;
		for(long long i = 0; i < 4*n -1; ++i){
			scanf("%lld%lld", &x, &y);
			points.push_back({x, y});
			x_axis[x]++; y_axis[y]++;
		}

		for(auto itr: x_axis){
			if(itr.second&1)
				x = itr.first;
		}
		for(auto itr: y_axis){
			if(itr.second&1)
				y = itr.first;
		}

		cout << x << " " << y << endl;


	}
}