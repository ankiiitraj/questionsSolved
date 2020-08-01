#include <bits/stdc++.h>
using namespace std;

string a, b, c;
int n, m, o;
int dp[101][101][101];
int solve(int i, int j, int k){
    if(i == 0 or j == 0 or k == 0)
        return 0;

    if(dp[i][j][k] != -1)
        return dp[i][j][k];

    if(a[i -1] == b[j -1] and a[i -1] == c[k -1]){
        return dp[i][j][k] = solve(i -1, j -1, k -1) +1;
    }
    
    return dp[i][j][k] = max({solve(i -1, j, k), solve(i, j -1, k), solve(i, j, k -1)});

}


int main(){
    int t; cin >> t; while(t--){
        cin >> n >> m >> o >> a >> b >> c;
        memset(dp, -1, sizeof dp);
        cout << solve(n, m, o) << endl;
    }
}