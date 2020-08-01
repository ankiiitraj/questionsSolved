#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t; while(t--){
        int n, m;
        string a, b;
        cin >> n >> m >> a >> b;
        
        int dp[n +1][m +1];
        memset(dp, 0, sizeof dp);
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(a[i -1] == b[j -1]){
                    dp[i][j] = dp[i -1][j -1] +1;
                }else{
                    dp[i][j] = max(dp[i][j -1], dp[i -1][j]);
                }
            }
        }
        
        cout << n - dp[n][m] + m - dp[n][m] << endl;
    }
}