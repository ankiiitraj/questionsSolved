#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define pii pair <int, int>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int N = 1000005; // 1e6 +5
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

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int n, k;
		string s, temp, ans;
		cin >> n >> k >> s;
		vector <string> v(k);

		sort(all(s));

		for(int i = 0; i < n; i++){
			v[i%k] += s[i];
		}
		
		sort(all(v));
		// debug(v);
		bool flag = 0;
		int idx = -1;
		for(int i = 0; i < n/k; ++i){
			for(int j = 0; j < k -1; ++j){
				if(v[j][i] != v[j +1][i]){
				// cout << v[j][i] << " " << v[j +1][i] << endl;
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
			idx = i;
			ans += v[k -1][i];

		}
		if((int)(v[k -1].length() -1) > idx){
			ans += v[k -1][idx +1];
		}
		if(ans.length() > 1){
			for(int i = 0; i < k -1; ++i){
				if(idx +1 <= v[i].length() -1 and v[i][idx +1] < ans[idx +1]){
					ans += v[i][idx +1];
				}else if(idx == v[i].length() -1 and v[i][idx] < ans[idx +1]){
					ans += v[i][idx];
				}
			}
		}
		// ans += v[k -1][v[k -1].length() -1];
	
		// }else{
		// 	for(int i = 0; i < k; ++i){
		// 		if(v[i][idx] < v[k -1][idx]){
		// 			v[k -1] += v[i][idx];
		// 		}
		// 	}
		// }


		// for(int i = 0; i )

		// for(int i = 0; i < k -1; ++i){
		// 	if(v[i].length() > 1LL){
		// 		temp += v[i][v[i].length() -1];
		// 	}
		// }

		sort(all(ans));
		// int end = ans.length() -1;
		cout << ans << endl;
	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	