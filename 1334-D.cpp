#include <bits/stdc++.h>
#define int long long int
#define len length
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
		int n, l, r, flag = 0;
		cin >> n >> l >> r;

		if(l == n*(n -1) +1){
			cout << 1 << endl;
			continue;
		}
		if(r == n*(n -1) +1){
			r--;
			flag = 1;
		}

		int cnt = r - l +1, total = n*(n -1);
		int cur = 0, start, end;
		for(int i = 1; i < n; ++i){
			cur += 2*(n -i);
			if(l <= cur){
				start = i;
				break;
			}
		}
		cur = 0;
		for(int i = 1; i < n; ++i){
			cur += 2*(n -i);
			if(r <= cur){
				end = i;
				break;
			}
		}

		for(int i = start; i <= end; ++i){
			int jStart = 1, jEnd = 2*(n -i), k = i +1;
			if(i == start){
				jStart = l - ((i -1)*(2*2*(n -1) + (i -2)*(-2)))/2;
				if(jStart&1)
					k = i +1 + jStart/2;
				else
					k = i +1 + jStart/2 -1;
			}
			if(end == i){
				jEnd = (r - ((i -1)*(2*2*(n -1) + (i -2)*(-2)))/2);
			}
			// debug(i, jStart, jEnd, k);
			for(int j = jStart; j <= jEnd; ++j){
				if(j&1)
					cout << i << " ";
				else
					cout << k << " ", ++k;
			}
		}
		if(flag)
			cout << "1 ";
		cout << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	