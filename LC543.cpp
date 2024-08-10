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
    int func(TreeNode* node, int& maxh){
        if(node== NULL){
            return 0;
        }

        int leftH= func(node->left, maxh);
        int rightH= func(node->right, maxh);

        maxh= max(maxh, leftH +rightH);
        return 1 + max(leftH, rightH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxh=0;
        func(root, maxh);
        return maxh;
    }
};