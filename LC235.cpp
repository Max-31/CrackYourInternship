/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node==NULL || node==p || node==q) return node;

        TreeNode* leftie= lowestCommonAncestor(node->left, p,q);
        TreeNode* rightie= lowestCommonAncestor(node->right, p,q);

        if(leftie && rightie){
            return node;
        } 
        else{
            if(leftie) return leftie;
            if(rightie) return rightie;
        }
        return NULL;
    }
};