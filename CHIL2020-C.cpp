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

/*------- sum of elements in range 1 to pos (1-Based Indexing) -------*/
void update(int pos, int n, int val, vector<int> &BIT){
	while(pos <= n){
		BIT[pos] +=val;
		pos += (pos&-pos);
	}
}

int query(int pos, vector<int> &BIT){
	int res = 0;
	while(pos >= 1){
		res += BIT[pos];
		pos -= (pos&-pos);
	}
	return res;
}

void solve(){
	int n, q, ty;
	string s;	
	cin >> n >> q >> s;
	s = '!' + s;
	vector<vector<int>> fre(n +1, vector<int>(26, 0));
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 26; ++j){
			fre[i][j] = fre[i -1][j];
		}
		fre[i][s[i] - 'a']++;
	}

	vector<vector<int>> BIT(26, vector<int>(n +1, 0));

	while(q--){
		cin >> ty;
		if(ty == 1){
			int pos;
			char c;
			cin >> pos >> c;
			update(pos, n, -1, BIT[s[pos] - 'a']);
			update(pos, n, +1, BIT[c - 'a']);
			s[pos] = c;
		}else{
			int l, r, k;
			cin >> l >> r >> k;
			int cnt_of_letters[26];
			for(int i = 0; i < 26; ++i){
				int cnt = fre[r][i] - fre[l -1][i];
				cnt += (query(r, BIT[i]) - query(l -1, BIT[i]));
				cnt_of_letters[i] = cnt;
			}
			int cnt = 0, ans;
			for(int i = 0; i < 26; ++i){
				cnt += cnt_of_letters[i];
				if(cnt >= k){
					ans = i;
					break;
				}
			}
			cout << (char)(ans + 'a') << endl;
		}
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
	