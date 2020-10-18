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
const int MOD = 2; // 1e9 + 7
const int MAXN = 1000005; // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

vector<vi> dp(201);
void pre(int n){
    vi res = {1};
    dp[1] = res;
    for(int i = 1; i < n; ++i){
        vi prev = res;
        res.assign((i * (i +1))/2 +1, 0);
        vi m(i +1, 1);

        for(int j = 0; j < i +1; ++j){
            for(int k = 0; k < prev.size(); ++k){
                res[k + j] = (res[k + j] + (m[j] * prev[k] % MOD)) % MOD;
            }
        }
        dp[i +1] = res;
    }
    return;
}

void solve(){
    int n, k;
    cin >> n >> k;

    cout << dp[n][k] << endl;
}

signed main()
{
    faster;
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    pre(200);
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
    