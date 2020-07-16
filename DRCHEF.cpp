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
		long long n, x, temp;
		scanf("%lld%lld", &n, &x);
		multiset<long long> s;
		for(int itr = 0; itr < n; ++itr)
		{
			scanf("%lld", &temp);
			s.insert(temp);
		}
		long long cnt = 0;
		

		while(!s.empty()){
			// if(cnt > 10)
			// 	break;
			auto itr = (s.lower_bound(x));

			cnt++;
			if(x < *s.begin()){
				long long cur = *s.rbegin();
				s.erase(s.find(*s.rbegin()));
				if((cur - x)*2 > 0)
					s.insert(min((cur - x)*2, cur));

				x *= 2;
				// debug(x, s, '1');
				continue;
			}



			if(itr == s.end()){
				itr = s.lower_bound(*s.rbegin());
			}else if(*itr != x and itr != s.begin()){
				--itr;
			}

			auto new_itr = s.find(*itr);

			temp = *new_itr;
			temp = min(max(0LL, (*new_itr - x)*2), temp);
			if(x > min(x, *new_itr)*2 and x < *s.rbegin()){
				long long cur = *s.rbegin();
				s.erase(s.find(*s.rbegin()));
				if((cur - x)*2 > 0)
					s.insert(min(cur, (cur - x)*2));

				x *= 2;
				// debug(x, s, '2');
				continue;
			}
			x = min(x, *new_itr)*2;
			if(temp != *new_itr){
				if(temp != 0)
					s.insert(temp);
				s.erase(new_itr);
			}
			// debug(x, s, '3');
		}

		cout << cnt << endl;

	}
}