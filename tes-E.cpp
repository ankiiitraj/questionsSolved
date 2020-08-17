#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define vi vector<int>
#define si set<int>
#define pii pair <int, int>
#define sii set<pii>
#define vii vector<pii>
#define mii map <int, int>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
using namespace chrono;
/*
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

bool is_safe(int x, int y, int val, int sudo[][7], char color[][7], map<char, vector<pii>> &color_map){
	for(int i = 0; i < 7; ++i){
		if(sudo[x][i] == val or sudo[i][y] == val)
			return 0;
	}

	int col = color[x][y];
	for(auto itr: color_map[col]){
		if(sudo[itr.first][itr.second] == val){
			return 0;
		}
	}

	return 1;
}

pii solved(int sudo[][7]){
	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 7; ++j){
			if(!sudo[i][j]){
				return {i, j};
			}
		}
	}
	return {-1, -1};
}

bool rec(int sudo[][7], char color[][7], map<char, vector<pii>> &color_map){
	pii cors = solved(sudo);
	if(cors == make_pair(-1LL, -1LL)){
		return true;
	}

	for(int i = 1; i <= 7; ++i){
		if(is_safe(cors.first, cors.second, i, sudo, color, color_map)){
			sudo[cors.first][cors.second] = i;
			rec(sudo, color, color_map);
			if(solved(sudo) == make_pair(-1LL, -1LL)){
				return true;
			}
			sudo[cors.first][cors.second] = 0;
		}
	}
	return false;
}

void solve(){
	int sudo[7][7];
	map<char, vector<pii>> color_map;
	char color[7][7];
	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 7; ++j){
			cin >> sudo[i][j];
		}
	}
	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 7; ++j){
			cin >> color[i][j];
			color_map[color[i][j]].push_back({i, j});
		}
	}

	rec(sudo, color, color_map);

	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 7; ++j){
			cout << sudo[i][j] << " ";
		}
		if(i != 6)
			cout << endl;
	}

	return;
}

signed main()
{
	faster;
// #ifndef ONLINE_JUDGE
// 	freopen("ip.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// #endif
	// int t; cin >> t; while(t--)
		solve();
	return 0;
}


//Author : Ankit Raj
//Problem Link :

/*Snippets*/
/*
sieve - prime factorization using sieve and primes in range
zpower - pow with mod
plate - Initial template
bfs 
dfs
fenwik - BIT
binary_search
segment_tree
*/
	