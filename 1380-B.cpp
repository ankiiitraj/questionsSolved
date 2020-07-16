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

void solve(){
	string s, res;
	cin >> s;
	int n = s.length();
	vi temp(3, 0);
	vector<vi> suf_freq(n, temp);

	suf_freq[n -1][s[n -1] == 'R' ? 0 : s[n -1] == 'S' ? 1 : 2]++; 
	
	for(int i = n -2; i >= 0; --i){
		suf_freq[i] = suf_freq[i +1];
		suf_freq[i][s[i] == 'R' ? 0 : s[i] == 'S' ? 1 : 2]++;
	}


	for(auto itr: suf_freq){
		auto pos = max_element(all(itr));
		if(pos - itr.begin() == 0)
			res += 'P';
		else if(pos - itr.begin() == 1)
			res += 'R';
		else
			res += 'S';
	}
	cout << res << endl;
	
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
	