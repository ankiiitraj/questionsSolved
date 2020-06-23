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
		int n, c;
		cin >> n >> c;

		vector<pii> points(n);
		map<int, vector<pii>> m;

		for(int i = 0; i < n; ++i){
			cin >> points[i].first >> points[i].second;
		}
		for(int i = 0; i < n; ++i){
			m[points[i].second - points[i].first].push_back({points[i].first,points[i].second});
		}

		int steps = 0, checkpoints = 0;

		for(auto itr: m){
			vector<pii> temp = itr.second;
			map<int, vector<int>> new_map;
			for(auto vitr: temp){
				new_map[(c + (vitr.first%c))%c].push_back(vitr.first);
			}
			checkpoints += new_map.size();
			for(auto mitr: new_map){
				sort(all(mitr.second));
				int mid = mitr.second.size()&1 ? mitr.second.size()/2 : mitr.second.size()/2 -1;

				for(auto sitr: mitr.second){
					steps += (abs(sitr - (mitr.second[mid])))/c;
				}
			}

		}
		cout << checkpoints << " " << steps << endl;

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	