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
    bool findsym(TreeNode* lefts, TreeNode* rights){
        if(lefts == NULL || rights == NULL){
            return lefts==rights;
        }

        if(lefts->val != rights->val) return false;

        bool leftside= findsym(lefts->left, rights->right);
        bool rightside= findsym(lefts->right, rights->left);

        return leftside & rightside;

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return findsym(root->left, root->right);
    }
};