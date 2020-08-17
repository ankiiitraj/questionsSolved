/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int helper(TreeNode *node, int *res){
    if(node->right == NULL and node->left == NULL){
        *res = max(*res, node->val);
        return node->val;
    }else if(node->left == NULL){
        int right = helper(node->right, res) + node->val;
        *res = max({*res, right, node->val});
        return max({node->val, right});
    }else if(node->right == NULL){
        int left = helper(node->left, res) + node->val;
        *res = max({*res, left, node->val});
        return max({node->val, left});
    }else{
        int left = helper(node->left, res) + node->val, right = helper(node->right, res) + node->val;
        *res = max({*res, left + right - node->val, node->val, right, left});
        return max({left, right, node->val});
    }
} 
int maxPathSum(TreeNode* node) {
    int res = INT_MIN;
    helper(node, &res);
    return res;
}