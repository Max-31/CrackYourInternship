/**
 * Definition for a binary tree root.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;


        TreeNode* leftie= lowestCommonAncestor(root->left, p, q);
        TreeNode* rightie= lowestCommonAncestor(root->right, p, q);

        if(root==p || root==q) return root;

        if(leftie==NULL && rightie==NULL) return NULL;
        else if(leftie!=NULL && rightie==NULL) return leftie;
        else if(leftie==NULL && rightie!=NULL) return rightie;
        return root;
    }
};