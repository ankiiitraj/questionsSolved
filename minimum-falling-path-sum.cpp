class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        for(int i = n -2; i >= 0; --i){
            for(int j = 0; j < m; ++j){
                if(j -1 < 0){
                    a[i][j] += min(a[i +1][j], a[i +1][j +1]);
                }else if(j +1 > n -1){
                    a[i][j] += min(a[i +1][j], a[i +1][j -1]);
                }else{
                    a[i][j] += min({a[i +1][j], a[i +1][j -1], a[i +1][j +1]});
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < m; ++i){
            ans = min(ans, a[0][i]);
        }
        return ans;
    }
};

// lINK : https://leetcode.com/problems/minimum-falling-path-sum/