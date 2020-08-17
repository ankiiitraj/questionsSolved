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

struct circle{
	int x, y, r;
};

bool check_if_intersect(circle c1, circle c2){
	return (c1.r + c2.r) > (double)sqrt((c1.x - c2.x)*(c1.x - c2.x) + (c1.y - c2.y)*(c1.y - c2.y)); 
}

void solve(){
	int n, xx, yy, rr;
	cin >> n;
	map<pair<pair<int, int>, int>, int> s;
	vector<circle> v;
	for(int i = 0; i < n; ++i){
		cin >> xx >> yy >> rr;
		s[{{xx, yy}, rr}]++;
		v.push_back({xx, yy, rr});
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i +1; j < n; ++j){
			if(check_if_intersect(v[i], v[j])){
				double r = sqrt(((v[i].x - v[j].x)*(v[i].x - v[j].x) + (v[i].y - v[j].y)*(v[i].y - v[j].y)))/2;
				double rR = sqrt(v[i].r*v[i].r + v[j].r*v[j].r);
				if(r != (int)r or 2*r != rR){
					continue;
				}
				
				double x = min(v[i].x, v[j].x)*1.0 + ((max(v[i].x, v[j].x) - min(v[i].x, v[j].x))/2);
				double y = min(v[i].y, v[j].y)*1.0 + ((max(v[i].y, v[j].y) - min(v[i].y, v[j].y))/2);
				if((x == (int)x and y == (int)y) and s[{{(int)x, (int)y}, (int)r}] != 0){
					ans += s[{{(int)x, (int)y}, (int)r}];
				}
			}
		}
	}
	
	cout << ans << endl;
}

signed main()
{
	faster;
#ifndef ONLINE_JUDGE
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
#endif
	int t; cin >> t; while(t--)
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
	