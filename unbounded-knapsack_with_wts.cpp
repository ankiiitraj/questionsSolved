#include <bits/stdc++.h>

using namespace std;

int dp[2005][2005];
// Complete the unboundedKnapsack function below.
int recurse(vector<int> &a, vector<int> &w, int pos, int sum, int n, int k){
    if(pos >= n){
        return 0;
    }
    if(dp[pos][sum] != -1)
        return dp[pos][sum];

    int res = -1;
    if(sum + w[pos] <= k){
        res = max(recurse(a, w, pos, sum + w[pos], n, k) + a[pos], recurse(a, w, pos +1, sum, n, k));
    }else{
        res = recurse(a, w, pos +1, sum, n, k);
    }

    return dp[pos][sum] = res;
}

int unboundedKnapsack(int k, vector<int> arr, vector<int> w) {
    memset(dp, -1, sizeof(dp));
    return recurse(arr, w, 0, 0, arr.size(), k);

}

int iterativeKnapsack(int k, vector<int> arr, vector<int> w, int n){
    int memo[n +1][k +1];
    memset(memo, 0, sizeof memo);
    arr.insert(arr.begin(), -1);
    w.insert(w.begin(), -1);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            if(j - w[i] >= 0){
                memo[i][j] = max(memo[i -1][j], memo[i][j - w[i]] + arr[i]);
            }else{
                memo[i][j] = memo[i -1][j];
            }
        }
        
        
    }
    int ans = -1;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= k; ++j){
            ans = max(ans, memo[i][j]);
        }
    }
    return ans;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
    int t; cin >> t; while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n), w(n);
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> w[i];
        }
        cout << unboundedKnapsack(k, arr, w) << endl;
        cout << iterativeKnapsack(k, arr, w, n) << endl;
    }
}
