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
const int INF = 1000000000;
int dp[1001][1001];

int recurse(vector<int> &a, int pos, int sum, int total, int n){
    if(pos >= n){
        if(sum == total)
            return 1;
        return 0;
    }
    if(dp[pos][sum] != -1)
        return dp[pos][sum];
    if(sum + a[pos] <= total)
        return (dp[pos][sum] = (recurse(a, pos +1, sum + a[pos], total, n) + recurse(a, pos +1, sum, total, n))%MOD);
    return dp[pos][sum] = recurse(a, pos +1, sum, total, n);
    
}

void solve(){
    int n, total;
    cin >> n;
    vi a(n);
    scnarr(a, n);
    a.insert(a.begin(), -1);
    memset(dp, -1, sizeof(dp));
    cin >> total;
    int memo[n +1][total +1];
    memset(memo, 0, sizeof(memo));
    for(int i = 0; i <= total; ++i)
        memo[0][i] = 0;
    for(int i = 0; i <= n; ++i)
        memo[i][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= total; ++j){
            if(j - a[i] >= 0){
                memo[i][j] = (memo[i -1][j - a[i]] + memo[i -1][j]) % MOD;
            }else{
                memo[i][j] = memo[i -1][j];
            }
        }
    }
    // cout << recurse(a, 0, 0, total, n) << endl;
    cout << memo[n][total] << endl;
}

signed main()
{
    faster;
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
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
    