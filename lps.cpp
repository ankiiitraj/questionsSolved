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

string longestPalindrome(string s) {
    if(s.length() == 0)
        return "";
    int n = s.length();
    int dp[n +1][n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i){
        dp[1][i] = 1;
        dp[0][i] = 1;
    }
    
    for(int i = 2; i <= n; ++i){
        for(int j = i -1; j < n; ++j){
            if(s[j] == s[j - i +1] and dp[i -2][j -1]){
                dp[i][j] = 1;
            }
        }
    }
    int idx_i = -1, idx_j = -1;
    for(int i = n; i >= 0; --i){
        int flag = 0;
        for(int j = 0; j < n; ++j){
            if(dp[i][j]){
                idx_i = i, idx_j = j;
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
    
    return s.substr(idx_j - idx_i +1, idx_i);
    
}

void solve(){
	string s;
	cin >> s;
	cout << longestPalindrome(s) << endl;
	
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
	