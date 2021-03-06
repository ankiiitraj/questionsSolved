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
int dp[1005][1005];
int recurse(vi &a, int pos, int prev){
    if(pos < 0){
        return 0;
    }
    if(dp[pos][prev] != -1)
        return dp[pos][prev];
    return dp[pos][prev] = max(a[pos] < a[prev] ? 1+ recurse(a, pos -1, pos) : 0, recurse(a, pos -1, prev));
}

void solve(){
    int n;
    memset(dp, 0, sizeof dp);
    cin >> n;
    vi a(n);
    scnarr(a, n);
    // a.push_back(1000);
    // cout << recurse(a, n -1, n) << endl;
    a.insert(a.begin(), -1);
    // for(int i = 0; i <= n; ++i)
    //     dp[i][0] = 1;
    int lis[n +1];
    lis[1] = 1;
    for(int i = 2; i <= n; ++i){
        lis[i] = 1;
        for(int j = 1; j < i; ++j){
            if(a[i] > a[j]){
                lis[i] = max(lis[i], lis[j] +1);
            }
        }
    }
    int ans = 1;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, lis[i]);
    }
    cout << ans << endl;
    
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
    