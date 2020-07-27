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
const int INF = 1000000007; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
int dp[51][10005];
int recurse(vi &a, int pos, int sum, int n, int total){
    if(pos >= n){
        return abs(sum - (total - sum));
    }
    if(dp[pos][sum] != -1)
        return dp[pos][sum];
    return dp[pos][sum] = min(recurse(a, pos +1, sum + a[pos], n, total), recurse(a, pos +1, sum, n, total));
}


void solve(){
    int n;
    cin >> n;
    vi a(n);
    scnarr(a, n);
    int total = 0;
    a.insert(a.begin(), -1);
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; ++i){
        total += a[i +1];
    }
    int memo[n +1][total +1];

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= total; ++j)
            memo[i][j] = 0;
    }

    memo[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= total; ++j){
            if(j - a[i] >= 0){
                memo[i][j] = memo[i -1][j] or memo[i -1][j - a[i]];
            }else{
                memo[i][j] = memo[i -1][j];
            }        
        }
    }

    int ans = 10*INF;
    for(int i = 0; i <= total; ++i){
        if(memo[n][i])
            ans = min(ans, abs(total - 2*i));
    }
    cout << ans << endl;
    // cout << recurse(a, 0, 0, n, total) << endl;
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
    