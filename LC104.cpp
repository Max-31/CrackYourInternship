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
public:
    int depth(TreeNode* node){
        if(node==NULL){
            return 0;
        }

        int left_height= depth(node->left);
        int right_height= depth(node->right);

        return 1 + max(left_height, right_height);
    }

    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};