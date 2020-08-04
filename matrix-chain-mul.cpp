#include<bits/stdc++.h>
using namespace std;

int dp[105][105];

int mcm(vector<int> &a, int i, int j){
    if(i >= j){
        return dp[i][j] = 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for(int itr = i; itr < j; ++itr){
        int cur_ans = mcm(a, i, itr) + mcm(a, itr +1, j) + a[i -1]*a[itr]*a[j];
        ans = min(ans, cur_ans);
    }
    return dp[i][j] = ans;
}

void print_mcm(int n){
    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif
    int t; scanf("%d", &t); while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                dp[i][j] = -1;
            }
        }
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }


        printf("%d\n", mcm(a, 1, n -1));
        
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < n; ++j){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
}