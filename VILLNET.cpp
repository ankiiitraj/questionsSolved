#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
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
	----------------------------------------------------------------------
	Things to remember : check for coners n = 1, pass references instead
*/
/* -------------------------------Solution Sarted--------------------------------------*/

//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

struct data{
	int one, two, three;
};

void bfs(int x1, int y1, int x2, int y2){
	queue<data> q;
	q.push({x1, y1, 0});

	while(!q.empty()){
		data cur = q.front();
		int x = cur.one, y = cur.two, lev = cur.three;
		if(x == x2 and y == y2){
			cout << cur.three << endl;
			return;
		}
		q.pop();
		if(x + 2 * y != 0 and __gcd(abs(x + 2 * y), y) == 1){
			q.push({x + 2 * y, y, lev +1});
		}
		if(x - 2 * y != 0 and __gcd(abs(x - 2 * y), y) == 1){
			q.push({x - 2 * y, y, lev +1});
		}

		if(y + 2 * x > 0 and __gcd(abs(x), abs(y + 2 * x)) == 1){
			q.push({x, y + 2 * x, lev +1});
		}else if(y + 2 * x < 0 and __gcd(abs(x), abs(y + 2 * x)) == 1){
			q.push({-x, -(y + 2 * x), lev +1});
		}

		if(y - 2 * x > 0 and __gcd(abs(x), abs(y - 2 * x)) == 1){
			q.push({x, y - 2 * x, lev +1});
		}else if(y - 2 * x < 0 and __gcd(abs(x), abs(y - 2 * x)) == 1){
			q.push({-x, -(y - 2 * x), lev +1});
		}
	}
}


void bfs1(int x1, int y1, int x2, int y2){
	queue<data> q;
	q.push({x1, y1, 0});

	while(!q.empty()){
		data cur = q.front();
		int x = cur.one, y = cur.two, lev = cur.three;
		if(x == x2 and y == y2){
			cout << cur.three << endl;
			return;
		}
		q.pop();
		if(x + 2 * y != 0 and x + 2 * y < 10 and __gcd(abs(x + 2 * y), y) == 1){
			q.push({x + 2 * y, y, lev +1});
		}
		if(x - 2 * y != 0 and x - 2 * y > -10 and __gcd(abs(x - 2 * y), y) == 1){
			q.push({x - 2 * y, y, lev +1});
		}

		if(y + 2 * x > 0 and y + 2 * x < 10 and __gcd(abs(x), abs(y + 2 * x)) == 1){
			q.push({x, y + 2 * x, lev +1});
		}else if(y + 2 * x < 0 and abs(y + 2 * x) < 10 and __gcd(abs(x), abs(y + 2 * x)) == 1){
			q.push({-x, -(y + 2 * x), lev +1});
		}

		if(y - 2 * x > 0 and y - 2 * x < 10 and __gcd(abs(x), abs(y - 2 * x)) == 1){
			q.push({x, y - 2 * x, lev +1});
		}else if(y - 2 * x < 0 and abs(y - 2 * x) < 10 and __gcd(abs(x), abs(y - 2 * x)) == 1){
			q.push({-x, -(y - 2 * x), lev +1});
		}
	}
}

void solve(){
	int n;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	queue<data> q;
	q.push({x1, y1, 0});

	if(x1 < 10 and x1 > -10 and x2 < 10 and x2 > -10 and y1 < 10 and y2 < 10){
		bfs1(x1, y1, x2, y2);
	}else{
		bfs(x1, y1, x2, y2);
	}
	
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
	