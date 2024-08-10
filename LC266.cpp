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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        
        TreeNode* ans= new TreeNode(root->val);

        queue<TreeNode*>q, q2;
        q.push(root);
        q2.push(ans);
        while(!q.empty() && !q2.empty()){
            TreeNode* node= q.front();
            q.pop();
            TreeNode* ansnode= q2.front();
            q2.pop();

            if(node->left!=NULL){
                ansnode->right= new TreeNode(node->left->val);

                q.push(node->left); q2.push(ansnode->right);
            }
            if(node->right!=NULL){
                ansnode->left= new TreeNode(node->right->val);

                q.push(node->right); q2.push(ansnode->left);
            }
        }

        return ans;
    }
};