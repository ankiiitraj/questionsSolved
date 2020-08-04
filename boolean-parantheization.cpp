#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1003;

vector<vector<pair<int, int>>> dp(305, vector<pair<int, int>>(305));
pair<int, int> un_touched = {-1, -1};

pair<int, int> solve(string &s, int i, int j){
    if(i == j){
        if(s[i] - '0'){
            return dp[i][j] = {1, 0};
        }
        return dp[i][j] = {0, 1};
    }
    if(i > j){
        return dp[i][j] = {0, 0};
    }

    if(dp[i][j] != un_touched)
        return dp[i][j];


    pair<int, int> ans = {0, 0};
    for(int k = i +1; k < j; k += 2){
        pair<int, int> left, right;
        if(dp[i][k -1] != un_touched){
            left = dp[i][k -1];
        }else{
            left = solve(s, i, k -1);
        }
        if(dp[k +1][j] != un_touched){
            right = dp[k +1][j];
        }else{
            right = solve(s, k +1, j);
        }
        if(s[k] == '&'){
            ans.first = (ans.first + ((left.first*right.first) % MOD)) % MOD;
            ans.second = (ans.second + ((left.first*right.second) % MOD)) % MOD;
            ans.second = (ans.second + ((left.second*right.first) % MOD)) % MOD;
            ans.second = (ans.second + ((left.second*right.second) % MOD)) % MOD;
        }else if(s[k] == '|'){
            ans.second = (ans.second + ((left.second*right.second) % MOD)) % MOD;
            ans.first = (ans.first + ((left.first*right.second) % MOD)) % MOD;
            ans.first = (ans.first + ((left.second*right.first) % MOD)) % MOD;
            ans.first = (ans.first + ((left.first*right.first) % MOD)) % MOD;
        }else{
            ans.first = (ans.first + ((left.first*right.second) % MOD)) % MOD;
            ans.first = (ans.first + ((left.second*right.first) % MOD)) % MOD;
            ans.second = (ans.second + ((left.first*right.first) % MOD)) % MOD;
            ans.second = (ans.second + ((left.second*right.second) % MOD)) % MOD;
        }
    }

    return dp[i][j] = ans;

}

signed main(){
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
    int t; cin >> t; while(t--){
        int n;
        string s;
        cin >> n >> s;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'T')
                s[i] = '1';
            else if(s[i] == 'F')
                s[i] = '0';
        }
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                dp[i][j] = {-1, -1};
            }
        }
        cout << solve(s, 0, n -1).first << endl;
    }
    return 0;
}


