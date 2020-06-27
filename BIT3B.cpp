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
/* -------------------------------Solution Sarted--------------------------------------*/
//Constants
const int MOD = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5

string rotate(string s){
	char temp = s[0];
	for(int i = 0; i < s.length() -1; ++i){
		s[i] = s[i +1];
	}
	s[s.length() -1] = temp;
	return s;
}

void solve(){
	int l;
	string s, q;
	cin >> l >> s;
	int n = s.length();

	if(l > 1){
		sort(all(s));
		cout << s << endl;
	}else{
		string ans = s;
		for(int i = 0; i < n; ++i){
			s = rotate(s);
			ans = min(ans, s);
		}
		cout << ans << endl;
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
