#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool is_palindrome(string &s, int i, int j){
    while(i <= j){
        if(s[i] != s[j])
            return 0;
        ++i, --j;
    }
    return 1;
}

int solve(string &s, int i, int j){
    if(i == j)
        return dp[i][j] = 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(is_palindrome(s, i, j)){
        return dp[i][j] = 0;
    }
    int ans = INT_MAX;
    for(int k = i; k < j; ++k){
        int one, two;
        if(dp[i][k] == -1){
            one = solve(s, i, k);
        }else{
            one = dp[i][k];
        }
        if(dp[k +1][j] == -1){
            two = solve(s, k +1, j);
        }else{
            two = dp[k +1][j];
        }
        ans = min(ans, one + two + 1);
    }
    return dp[i][j] = ans;
}

int solve_iterative(string s, int n){

    int dpi[n +1][n +1];
    
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            dpi[i][j] = INT_MAX;
        }
    }
    for(int l = 1; l <= n; ++l){
        for(int i = 0; i < n - l +1; ++i){
            int j = i + l -1;
            if(is_palindrome(s, i, j)){
                dpi[i][j] = 0;
            }else{
                for(int k = i; k < j; ++k){
                    dpi[i][j] = min(dpi[i][j], dpi[i][k] + dpi[k +1][j] + 1);
                }
            }
        }
    }
    // for(int i = 0; i <= n; ++i){
    //     for(int j = 0; j <= n; ++j){
    //         cout << dpi[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dpi[0][n -1];

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int t; cin >> t; while(t--){
        string s;
        cin >> s;
        int n = s.length();
        for(int i = 0; i <= n +1; ++i){
            for(int j = 0; j <= n +1; ++j){
                dp[i][j] = -1;
            }
        }
        // cout << solve(s, 0, n -1) << endl;
        cout << solve_iterative(s, n) << endl;
    }
}