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

string digi[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
map <string, int> digs = {{"1110111", 0}, {"0010010", 1}, {"1011101", 2}, {"1011011", 3}, {"0111010", 4}, {"1101011", 5}, {"1101111", 6}, {"1010010", 7}, {"1111111", 8}, {"1111011", 9}};
int n;

string dp[2005][2005];

string solve(vector <string> &s, int pos, int k){
	if(k == 0){
		string ans;
		for(int i = 0; i < n; ++i){
			if(digs.find(s[i]) == digs.end()){
				return "-1";
			}
			ans += to_string(digs[s[i]]);
		}
		return ans;
	}else if(pos >= n){
		return "-1";
	}

	if(dp[pos][k] != "")
		return dp[pos][k];

	string ans = "-1";
	for(int i = 9; i >= 0; --i){
		int cnt = 0;
		for(int j = 0; j < 7; ++j){
			if(s[pos][j] != digi[i][j] and s[pos][j] == '0'){
				cnt++;
			}else if(s[pos][j] != digi[i][j] and s[pos][j] == '1'){
				cnt = 5000;
				break;
			}
		}
		if(cnt <= k){
			string temp = s[pos];
			s[pos] = digi[i];
			dp[pos][k] = max(dp[pos][k], solve(s, pos +1, k - cnt));
			s[pos] = temp;
		}
	}
	return dp[pos][k];
}


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif

	{
		int k;
		cin >> n >> k;
		vector<string> s(n);

		for(int i = 0; i < n; ++i){
			cin >> s[i];
		}

		cout << (solve(s, 0, k)) << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	