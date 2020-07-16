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

bool cmp(pair<long long, long long> &a, pair<long long, long long> &b){
	if(a.first == b.first)
		return 0;
	return a.first > b.first;
}
long long int MAXN = 200005;
/*1-Based indexing*/
vector<long long> tree(4*MAXN, -1);
void build(vector<pair<long long, long long>> &a, long long l, long long r, long long root){
	if(l == r){
		tree[root] = a[l].first;
		return;
	}
	build(a, l, (l + r)/2, 2*root);
	build(a, (l + r)/2 +1, r, 2*root +1);
	tree[root] = max(tree[2*root], tree[2*root +1]);
}
long long query(long long ql, long long qr, long long l, long long r, long long root){
	if(ql <= l and qr >= r)
		return tree[root];
	if(ql > r or qr < l)
		return -1;
	return max(query(ql, qr, l, (l + r)/2, 2*root), query(ql, qr, (l + r)/2 +1, r, 2*root +1));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t;
	// scanf("%d", &t);
	// for(int test = 0; test < t; ++test)
	{
		long long n, q, ty, b, k, temp; 
		scanf("%lld%lld", &n, &q);

		vector<pair<long long, long long>> a(n +1);
		for(long long i = 0; i < n; ++i){
			scanf("%lld", &a[i +1].first);
		}
		for(long long i = 0; i < n; ++i){
			scanf("%lld", &a[i +1].second);
		}

        if(q <= 1000 and n <= 1000){
        	while(q--){
	            scanf("%lld%lld%lld", &ty, &b, &k);
	            if(ty == 1){
	                a[b].second = k;
	            }else{
	                if(b == k){
	                    printf("%lld\n", a[b].second);
	                }else if(b > k){
	                    if(a[k].first >= a[b].first){
	                        printf("-1\n");
	                        continue;
	                    }
	                    long long ans = a[b].second + a[k].second, flag = 0, prev = a[k].first;
	                    for(long long i = k +1; i < b; ++i){
	                        if(a[i].first > prev and a[i].first < a[b].first){
	                            ans += a[i].second;
	                            prev = a[i].first;
	                        }else if(a[i].first >= a[b].first){
	                            flag = 1;
	                            break;
	                        }
	                    }
	                    flag ? printf("-1\n") : printf("%lld\n", ans);
	                }else{
	                    if(a[b].first <= a[k].first){
	                        printf("-1\n");
	                        continue;
	                    }
	                    long long ans = a[b].second + a[k].second, flag = 0, prev = a[k].first;
	                    for(long long i = k -1; i > b; --i){
	                        if(a[i].first > prev and a[i].first < a[b].first){
	                            ans += a[i].second;
	                            prev = a[i].first;
	                        }else if(a[i].first >= a[b].first){
	                            flag = 1;
	                            break;
	                        }
	                    }
	                    flag ? printf("-1\n") : printf("%lld\n", ans);
	                }
	            }
	        }
	        return 0;   
        }

		build(a, 1, n, 1);
		long long prev, cnt = 0;
		vector<pair<long long, long long>> dp(n +1, {-1, 0}), dpr(n +1, {-1, 0});

		stack<pair<long long, long long>> until;
		for(long long i = 1; i <= n; ++i){
			dp[i] = {a[i].second, i};
			while(!until.empty() and until.top().first <= a[i].first){
				until.pop();
			}
			if(!until.empty()){
				dp[i].first += dp[until.top().second].first; 
				dp[i].second = dp[until.top().second].second; 
			}
			until.push({a[i].first, i});
		}

		for(long long i = n; i >= 1; --i){


			dpr[i] = {a[i].second, i};
			while(!until.empty() and until.top().first <= a[i].first){
				until.pop();
			}
			if(!until.empty()){
				dpr[i].first += dpr[until.top().second].first; 
				dpr[i].second = dpr[until.top().second].second; 
			}
			until.push({a[i].first, i});
			
		}


		while(q--){
			scanf("%lld%lld%lld", &ty, &b, &k);
			if(ty == 1){
				a[b].second = k;
				for(long long i = b; i <= n; ++i){
					dp[i] = {a[i].second, i};
					while(!until.empty() and until.top().first <= a[i].first){
						until.pop();
					}
					if(!until.empty()){
						dp[i].first += dp[until.top().second].first; 
						dp[i].second = dp[until.top().second].second; 
					}
					until.push({a[i].first, i});
				}

				for(long long i = b; i >= 1; --i){


					dpr[i] = {a[i].second, i};
					while(!until.empty() and until.top().first <= a[i].first){
						until.pop();
					}
					if(!until.empty()){
						dpr[i].first += dpr[until.top().second].first; 
						dpr[i].second = dpr[until.top().second].second; 
					}
					until.push({a[i].first, i});
					
				}				

			}else{
				if(b == k){
					printf("%lld\n", a[b].second);
				}else if(b > k){
					if(a[k].first >= a[b].first){
						printf("-1\n");
						continue;
					}
					long long ans, flag = 0;

					long long he = query(k +1, b -1 ,1, n, 1);
					if(he >= a[b].first)
						flag = 1;
					else
						ans = dpr[k].first - dpr[b].first + a[b].second;

					flag ? printf("-1\n") : printf("%lld\n", ans);
				}else{
					if(a[b].first <= a[k].first){
						printf("-1\n");
						continue;
					}
					long long ans, flag = 0;

					long long he = query(b +1, k -1 ,1, n, 1);
					if(he >= a[b].first)
						flag = 1;
					else
						ans = dp[k].first - dp[b].first + a[b].second;
					flag ? printf("-1\n") : printf("%lld\n", ans);
				}
			}
		}

	}
}