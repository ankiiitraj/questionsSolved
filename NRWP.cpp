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

struct particle{
	int y, x, p;
};


int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
	{
		int h, w, n;
		cin >> h >> w >> n;
		vector<vi> grid;
		vector <particle> particles(n);
		map <pii, pii> pos;

		vi temp(w);
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				cin >> temp[j];
			}
			grid.push_back(temp);
		}

		for(int i = 0; i < n; ++i){
			cin >> particles[i].y >> particles[i].x >> particles[i].p;
			pos.insert({{particles[i].y, particles[i].x}, {particles[i].p, i}});
		}


		int ans = -1;
		vector<bool>ansSigns;
		for(int j = 0; j < pow(2, n); ++j){
			int sumPartTwo = 0, sumPartOne = 0;
			
			set<pii> used;
			bitset<20> bit(j);
			vector<bool> bits(n, 0);
			for(int i = 0; i < n; ++i){
				bits[i] = bit[i];
			}
			reverse(all(bits));

			for(int i = 0; i < n; ++i){
				sumPartOne += (bits[i] == 0 ? -1 : 1) * (particles[i].p) * (grid[particles[i].y -1][particles[i].x -1]);
			}

			for(int i = 0; i < n; ++i){
				if((pos.find({particles[i].y +1, particles[i].x}) != pos.end()) and used.find({particles[i].y +1, particles[i].x}) != used.end()){
					sumPartTwo += (particles[i].p * (bits[i] == 0 ? -1 : 1)) * (pos[{particles[i].y +1, particles[i].x}].first * (bits[pos[{particles[i].y +1, particles[i].x}].second] == 0 ? -1 : 1));
				}
				if((pos.find({particles[i].y -1, particles[i].x}) != pos.end()) and used.find({particles[i].y -1, particles[i].x}) != used.end()){
					sumPartTwo += (particles[i].p * (bits[i] == 0 ? -1 : 1)) * (pos[{particles[i].y -1, particles[i].x}].first * (bits[pos[{particles[i].y -1, particles[i].x}].second] == 0 ? -1 : 1));
				}
				if((pos.find({particles[i].y, particles[i].x +1}) != pos.end()) and used.find({particles[i].y, particles[i].x +1}) != used.end()){
					sumPartTwo += (particles[i].p * (bits[i] == 0 ? -1 : 1)) * (pos[{particles[i].y, particles[i].x +1}].first * (bits[pos[{particles[i].y, particles[i].x +1}].second] == 0 ? -1 : 1));
				}
				if((pos.find({particles[i].y, particles[i].x -1}) != pos.end()) and used.find({particles[i].y, particles[i].x -1}) != used.end()){
					sumPartTwo += (particles[i].p * (bits[i] == 0 ? -1 : 1)) * (pos[{particles[i].y, particles[i].x -1}].first * (bits[pos[{particles[i].y, particles[i].x -1}].second] == 0 ? -1 : 1));
				}
				used.insert({particles[i].y, particles[i].x});
			}
			// cout << sumPartOne + sumPartTwo << endl;
			if(sumPartOne + sumPartTwo > ans){
				ans = sumPartOne + sumPartTwo;
				ansSigns = bits;
			}
		}
		cout << ans << endl;
		for(auto itr: ansSigns){
			cout << (itr == 0 ? -1 : 1) << " ";
		}
		cout << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	