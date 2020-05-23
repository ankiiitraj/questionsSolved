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
const int MOD = 1e9+7; // 1e9 + 7
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
vector <string> grid;

int countPaths(int src, int dest, int w, int h) 
{ 
	int maze[h +10][w +10] = {0};

	for(int i = 0; i < h +10; ++i){
		for(int j = 0; j < w +10; ++j){
			maze[i][j] = 0;
		}
	}

	maze[0][src] = 1;

	if(grid[h][dest] != grid[0][src]){
    	return 0;
    }
    
    for (int i = 1; i <= h ; i++) 
    { 
        for (int j = 0; j <= w; j++) 
        { 
            if(grid[i -1][j] == grid[i][j]){
            	maze[i][j] = (maze[i][j] + maze[i -1][j])%MOD;
            }
            if(j > 0 and grid[i -1][j -1] == grid[i][j]){
            	maze[i][j] = (maze[i][j] + maze[i -1][j -1])%MOD;
            }
            if(j < w and grid[i -1][j +1] == grid[i][j]){
            	maze[i][j] = (maze[i][j] + maze[i -1][j +1])%MOD;
            }
        } 
    } 
  	return maze[h][dest]%MOD;
}

int32_t main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	// int t; cin >> t; while(t--)
	{
		int n, q;
		cin >> n >> q;
		string type;

		while(q--){
			cin >> type;
			if(type == "path"){
				int l, r;
				cin >> l >> r;
				--l, --r;
				if(grid.size() < 2){
					cout << 0 << endl;
				}else{
					cout << countPaths(l, r, n -1, grid.size() -1)%MOD << endl;
				}
			}else if(type == "add"){
				string temp;
				cin >> temp;
				grid.push_back(temp);
			}else{
				grid.erase(grid.begin());
			}
		}		

	}
	return 0;
}


//Author : Ankit Raj
//InSearchForMeanings
//Problem Link :
	