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
#include <time.h>
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
vi c[6000];
int n, m, k;

int calc(vi score){
	int marks = 0, minMarks = 100000000000000000;
	for(int i = 0; i < k; ++i){
		marks = 0;
		for(int j = 0; j < n; ++j){
			if(score[j] == c[i][j])
				marks++;
		}
		minMarks = min(minMarks, marks);
	}
	return minMarks;
}

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	srand(chrono::steady_clock::now().time_since_epoch().count());
	int t; cin >> t; while(t--)
	{
		int temp;
		cin >> n >> m >> k;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < k; ++j){
				cin >> temp;
				c[j].push_back(temp);
			}
		}
		vi score(n);
		int _maxScore = -1;
		vi ans;
		for(int i = 0; i < 150; ++i){
			for(int j = 0; j < n; ++j){
				score[j] = rand()%m +1;
			}
			temp = calc(score);
			if(temp > _maxScore){
				_maxScore = temp;
				ans = score;
			}
		}
		
		for(int i = 0; i < n; ++i)
			cout << ans[i] << " ";
		cout << endl;

	}
	return 0;
}
