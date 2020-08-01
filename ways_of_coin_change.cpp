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
int dp[400][400];
int rec(int arr[], int n, int pos, int arr_size){
    if(n == 0){
        return 1;
    }else if(n < arr[0] or pos >= arr_size){
        return 0;
    }
    
    if(dp[n][pos] != -1)
        return dp[n][pos];
    
    int ans = 0, temp_n = n;
    while(temp_n >= 0){
        ans += rec(arr, temp_n, pos +1, arr_size);
        temp_n -= arr[pos];
    }
    
    return dp[n][pos] = ans;
    
}

int iterate(int value, int n, int arr[]){
    
    int dp[value +1];
    
    for(int i = 0; i <= value; ++i){
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int j = 0; j < n; ++j){
        for(int i = arr[j]; i <= value; ++i){
            dp[i] += dp[i - arr[j]];
        }
    }
    
    return dp[value] < 0 ? 0 : dp[value];
}

void solve(){
    memset(dp, -1, sizeof dp);
    int n, arr_size;
    cin >> arr_size;
    int arr[arr_size];
    for(int i = 0; i < arr_size; ++i)
        cin >> arr[i];
    sort(arr, arr + arr_size);
    cin >> n;
    // cout << rec(arr, n, 0, arr_size) << endl;
    cout << iterate(n, arr_size, arr) << endl;
    
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
    