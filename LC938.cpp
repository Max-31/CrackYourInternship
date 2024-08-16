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
    int rangeSumBST(TreeNode* node, int l, int h) {
        if(!node) return 0;
        
        int leftie, rightie=0;
        if(l>node->val) leftie=0;
        else leftie= rangeSumBST(node->left, l, h);
        
        
        if(h<node->val) rightie=0;
        else rightie= rangeSumBST(node->right, l, h);
        
        if(l<=node->val && node->val<=h) return node->val+leftie+rightie;
        return leftie+rightie;
    }
};