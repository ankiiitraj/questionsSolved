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
int memo[101][101];
int rodCuttingRecursive(vi &a, int pos, int cur_length){
    if(pos <= 0 or cur_length == 0){
        return 0;
    }
    
    if(memo[pos][cur_length] != -1)
        return memo[pos][cur_length];
    
    if(pos <= cur_length){
        return memo[pos][cur_length] = max(rodCuttingRecursive(a, pos, cur_length - pos) + a[pos], rodCuttingRecursive(a, pos -1, cur_length));
    }else{
        return memo[pos][cur_length] = rodCuttingRecursive(a, pos -1, cur_length);
    }
    
}

int rodCuttingItterative(vi &a, int n){
    if(n == 1){
        return a[1];
    }
    int ans = 0;
    int dp[n +1] = {0};
    dp[1] = a[1];
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            dp[i] = max(dp[i - j] + a[j], dp[i]);
            ans = max(dp[i], ans);
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    memset(memo, -1, sizeof memo);
    vi a(n);
    scnarr(a, n);
    a.insert(a.begin(), -1);
    // cout << rodCuttingRecursive(a, n, n) << endl;
    cout << rodCuttingItterative(a, n) << endl;
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
    