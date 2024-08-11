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
    int inorder(TreeNode *node, bool &ans){
        if(node==NULL) return 0;

        int left= inorder(node->left, ans);
        int right= inorder(node->right, ans);

        if(abs(left-right)>1) ans= false;

        // cout<<node->val<<": "<<left<<", "<<right<<"\n";

        return 1+max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans= true;
        inorder(root, ans);

        return ans;
    }
};