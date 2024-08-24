class Solution {
public:
    int ans = 0 ;
    void inorder(TreeNode* node, long long sum){
        if(node == NULL) return;

        if(sum == node -> val)
            ans++;
        
        inorder(node->left,sum - node->val);
        inorder(node->right,sum - node->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
       if(root){
        inorder(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
       }
       return ans;
    }
};