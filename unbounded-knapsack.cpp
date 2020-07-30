#include <bits/stdc++.h>

using namespace std;

int dp[2005][2005];
// Complete the unboundedKnapsack function below.
int recurse(vector<int> &a, int pos, int sum, int n, int k){
    if(pos >= n){
        return sum;
    }
    if(dp[pos][sum] != -1)
        return dp[pos][sum];
    int res = -1;
    if(sum + a[pos] <= k){
        res = max(recurse(a, pos, sum + a[pos], n, k), recurse(a, pos +1, sum, n, k));
    }else{
        res = recurse(a, pos +1, sum, n, k);
    }
    return dp[pos][sum] = res;
}

int unboundedKnapsack(int k, vector<int> arr) {
    memset(dp, -1, sizeof(dp));
    return recurse(arr, 0, 0, arr.size(), k);

}

int iterativeKnapsack(vector<int> &arr, int n, int k){
    arr.insert(arr.begin(), -1);
    int memo[n +1][k +1];
    memset(memo, 0, sizeof memo);

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= k; ++j){
            if(j - arr[i] >= 0){
                memo[i][j] = max(memo[i -1][j], memo[i][j - arr[i]] + arr[i]);
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
    int t; cin >> t; while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        cout << unboundedKnapsack(k, arr) << endl;
        cout << iterativeKnapsack(arr, n, k) << endl;

    }
}
