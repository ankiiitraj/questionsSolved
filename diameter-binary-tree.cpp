int helper(Node *node, vector<pair<int, int>> &dp){
    if(node->right == NULL and node->left == NULL){
        return 1;
    }else if(node->left == NULL){
        int right = helper(node->right, dp);
        dp.push_back({0, right});
        return right +1;
    }else if(node->right == NULL){
        int left = helper(node->left, dp);
        dp.push_back({left, 0});
        return left +1;
    }else{
        int left = helper(node->left, dp), right = helper(node->right, dp);
        dp.push_back({left, right});
        return max(left, right) +1;
    }
}

int diameter(Node* node) {
    vector<pair<int, int>> dp;
    helper(node, dp);
    int res = 1;
    for(auto itr: dp){
        res = max(res, itr.first + itr.second +1);
    }
    return res;
}