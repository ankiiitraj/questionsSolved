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

int rec(int arr[], int n, int arr_size, int dp[]){
    if(n == 0){
        return 0;
    }else if(n < arr[0LL]){
        return INF;
    }
    
    if(dp[n] != -1)
        return dp[n];
        
    int ans = INF;
    for(int i = 0; i < arr_size; ++i){
        ans = min(rec(arr, n - arr[i], arr_size, dp) +1, ans);
    }
    
    return dp[n] = ans;
    
}

int iterate(int a[], int value, int n){
    int dp[value +1];
    dp[0] = 0;
    for(int i = 1; i <= value; ++i){
        dp[i] = INF;
        for(int j = 0; j < n; ++j){
            if(a[j] <= i){
                dp[i] = min(dp[i - a[j]] +1, dp[i]);
            }
        }
    }
    return dp[value];
}

void solve(){
    int value, n;
    cin >> value >> n;
    int arr[n], dp[value +1];
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    // int ans = rec(arr, value, n, dp); 
    int ans = iterate(arr, value, n); 
    if(ans > value){
        cout << "-1\n";
    }else{
        cout << ans << endl;
    }
    
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
    