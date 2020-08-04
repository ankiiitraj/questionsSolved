#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t; while(t--){
        string a, b;
        cin >> a;
        b = a;
        int n = a.length();
        reverse(b.begin(), b.end());
        int dp[n +1][n +1];
        memset(dp, 0, sizeof dp);
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(a[i -1] == b[j -1]){
                    dp[i][j] = dp[i -1][j -1] +1;
                }else{
                    dp[i][j] = max(dp[i -1][j], dp[i][j -1]);
                }
            }
        }
        
        cout << n - dp[n][n] << endl;
        
    }
}