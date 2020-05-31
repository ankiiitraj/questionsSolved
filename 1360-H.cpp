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
		int n, m;
		cin >> n >> m;
		set<int> set;
		if(m == 1){
			string s;
			cin >> s;
			if(s[0] == '0'){
				cout << 1;
			}else{
				cout << 0;
			}
			cout << endl;
			continue;
		}
		int total = pow(2, m);
		int median = (total - 1)/2, left = median +1, right = total - left;
		for(int i = 0; i < n; ++i){
			string s;
			cin >> s;
			int cur = 0;
			for(int j = m -1, k = 0; j >= 0; --j, ++k){
				cur += (s[j] - '0')*(pow(2, k));
			}
			set.insert(cur);
			if(cur > median){
				right--;
				if(!(left - right <= 1 and left - right > -1)){
					for(int j = median -1; j >= 0; --j){
						if(set.find(j) == set.end()){
							median = j;
							left--;
							right++;
							break;
						}
					}
				}
			}else if(cur < median){
				left--;
				if(!(left - right <= 1 and left - right > -1)){
					for(int j = median +1; j < total; ++j){
						if(set.find(j) == set.end()){
							median = j;
							left++;
							right--;
							break;
						}
					}
				}
			}else{
				if(left > right){
					for(int j = median -1; j >= 0; --j){
						if(set.find(j) == set.end()){
							median = j;
							left = right = left -1;
							break;
						}
					}
				}else{
					for(int j = median +1; j < total; ++j){
						if(set.find(j) == set.end()){
							median = j;
							right--;
							break;
						}
					}
				}
			
			}
			// debug(set, cur, median, left, right);
		}
		bitset<60> ans(median);
		for(int i = m -1, j = 0; j < m; --i, ++j)
			cout << ans[i];
		cout << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	