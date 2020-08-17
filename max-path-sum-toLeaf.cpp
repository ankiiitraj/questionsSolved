int helper(Node *node, int *res){
    if(node->right == NULL and node->left == NULL){
        return node->data;
    }else if(node->left == NULL){
        int right = helper(node->right, res) + node->data;
        return right;
    }else if(node->right == NULL){
        int left = helper(node->left, res) + node->data;
        return left;
    }else{
        int left = helper(node->left, res) + node->data, right = helper(node->right, res) + node->data;
        *res = max({*res, left + right - node->data});
        return max({left, right});
    }
}
int maxPathSum(Node* root)
{ 
    int res = INT_MIN;
    helper(root, &res);
    return res;
}