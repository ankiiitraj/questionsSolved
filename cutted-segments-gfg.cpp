#include <bits/stdc++.h>
#include <time.h>
#define int long long int
#define pb push_back
#define all(a) a.begin(), a.end()
#define scnarr(a, n) for (int i = 1; i <= n; ++i) cin >> a[i]
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

int rec(int n, int a[], int dp[]){
    if(n == 0){
        return 0;
    }else if(n < a[0]){
        return -INF;   
    }
    
    if(dp[n] != -1)
        return dp[n];
    
    return dp[n] = max({rec(n - a[0], a, dp) +1, rec(n - a[1], a, dp) +1, rec(n - a[2], a, dp) +1});
    
}

int iterate(int n, int a[]){
    int dp[n +1] = {0};
    for(int i = 1; i <= n; ++i){
        if(i >= a[0]){
            dp[i] = max({dp[i - a[0]] +1, i - a[1] >= 0 ? dp[i - a[1]] +1 : -INF, i - a[2] >= 0 ? dp[i - a[2]] +1 : -INF});
        }else{
            dp[i] = -INF;
        }
    }
    return dp[n];
}

void solve(){
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    int dp[n +1];
    memset(dp, -1, sizeof dp);
    sort(a, a +3);
    // cout << rec(n, a, dp) << endl;
    cout << iterate(n, a) << endl;
    
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
    