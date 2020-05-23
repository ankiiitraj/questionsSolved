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

void LPSArray(string pat, int M, int* lps); 

int KMP(string pat, string txt) 
{ 
	int M = pat.length(); 
	int N = txt.length(); 
	int lps[M]; 
	LPSArray(pat, M, lps); 

	int i = 0, j = 0, cnt = 0;
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			cnt++;
			j = lps[j - 1]; 
		}
		else if (i < N && pat[j] != txt[i]) { 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
	return cnt;
} 

void LPSArray(string pat, int M, int* lps) 
{
	int len = 0; 

	lps[0] = 0;
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else
		{ 
			if (len != 0) { 
				len = lps[len - 1]; 
			}else{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 





int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif

	int t; cin >> t; while(t--)
	{
		string a, b;
		int n, ans = -1;
		cin >> a >> b >> n;
		vector <string> v(n);
		vi beauty(n);

		for(int i = 0; i < n; ++i){
			cin >> v[i] >> beauty[i];
		}

		for(int i = 0; i < n; ++i){
			string cur = v[i];
			for(int j = 1; j <= cur.length(); ++j){
				int curAns = 0;
				auto itr1 = a.rfind(cur.substr(0, j)), itr2 = b.find(cur.substr(j));
				if(itr1 == string::npos or itr2 == string::npos){
					continue;
				}
				string temp = a.substr(0, itr1 + j) + b.substr(itr2);
				for(int x = 0; x < n; ++x){
					curAns += KMP(v[x], temp)*beauty[x];
				}
				// cout << cur << " " << itr1 << " " << itr2 << " " << j << " " << temp << " " << curAns << endl;
				ans = max(ans, curAns);
			}

		}

		// for(int i = 1; i <= a.length(); ++i){
		// 	string cur = a.substr(0, i);
		// 	for(int j = 1; j <= b.length(); ++j){
		// 		string temp = cur + b.substr(b.length() - j);
		// 		int curAns = 0;
		// 		for(int x = 0; x < n; ++x){
		// 			curAns += KMP(v[x], temp)*beauty[x];
		// 		}
		// 		ans = max(ans, curAns);
		// 	}

		// }



		cout << ans << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	