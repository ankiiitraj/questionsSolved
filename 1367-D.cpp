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
const int INF = 1000005; // 1e6 +5
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
	int test; cin >> test; while(test--)
	{
		string s, u;
		int freq[26] = {0};
		cin >> s;
		int n = s.length(), m;
		cin >> m;
		string t(m, '_');
		vi b(m), c(m, INF);
		scnarr(b, m);
		sort(all(s));
		reverse(all(s));
		for(auto itr: s){
			freq[itr - 'a']++;
			if(freq[itr - 'a'] == 1){
				u += itr;
			}
		}
		// cout << u << endl;
		while(b != c){
			int cnt = 0;
			vi zeroes;
			for(int i = 0; i < m; ++i){
				if(b[i] == 0){
					b[i] = INF;
					cnt++;
					zeroes.push_back(i);
				}

			}
			debug(b);
			for(int i = 25; i >= 0; --i){
				if(freq[i] >= cnt){
					for(auto itr: zeroes)
						t[itr] = (char)(i + 'a');
					freq[i] = 0;
					break;
				}
				freq[i] = 0;
			}
			for(auto itr: zeroes){
				for(int i = 0; i < m; ++i){
					if(b[i] != INF){
						b[i] -= abs(i - itr);
					}
				}
			}

		}

		cout << t << endl;



	}
	return 0;
}
// lojemgnegj


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	 