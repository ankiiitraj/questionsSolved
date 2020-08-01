#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
using namespace std;

int dp[101][101];

int rec(string &a, string &b, int n, int m){
    if(n < 0 or m < 0)
        return 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    rec(a, b, n -1, m);
    rec(a, b, n, m -1);
    
    if(a[n] == b[m]){
        return dp[n][m] = 1+ rec(a, b, n -1, m -1);
    }

    return dp[n][m] = 0;
}

int solve(string a, string b, int n, int m){
    rec(a, b, n, m);
    int ans = 0;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int iterate(string a, string b, int n, int m){
    a = '!' + a;
    b = '!' + b;
    if(m > n){
        string temp = a;
        a = b; b = temp;
        n ^= m; m ^= n; n ^= m;
    }
    int dp[n +2][m +2] = {0}, ans = 0;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j]){
                dp[i][j] = dp[i -1][j -1] +1;
            }else{
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main(){
    faster;
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
    int t; cin >> t; while(t--){
        int n, m;
        memset(dp, -1, sizeof dp);
        string a, b;
        cin >> n >> m >> a >> b;
        
        cout << solve(a, b, n -1, m -1) << endl;
        // cout << iterate(a, b, n, m) << endl;
        
    }
    
    
    
    return 0;
}