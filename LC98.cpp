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
    bool inorder(TreeNode* node, long long l, long long r){
        if(!node) return true;

        bool leftie= inorder(node->left, l, node->val);
        bool rightie= inorder(node->right, node->val, r);

        bool ans= leftie & rightie;
        bool ans2=false;

        if(l<node->val && node->val<r) ans2= true;
        return ans & ans2;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return true;
        return inorder(root, LONG_MIN, LONG_MAX);
    }
};