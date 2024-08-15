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
class Solution {
    bool inorder(TreeNode* node, int target, int sum){
        if(node == NULL){
            return false;
        }
        if(node->left==NULL && node->right==NULL){
            if(sum+node->val==target) return true;
            else return false;
        }

        bool leftie= inorder(node->left, target, sum+node->val);
        bool rightie= inorder(node->right, target, sum+node->val);

        return leftie | rightie;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return inorder(root, targetSum, 0);
    }
};