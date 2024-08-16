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
    void inorder(TreeNode* node, int &ans, int &k){
        if(!node){
            return;
        }

        inorder(node->left, ans, k);
        cout<<node->val<<" "<<k<<endl;
        k--;
        if(k==0) {
            ans= node->val;
            return;
        }
        inorder(node->right, ans, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        inorder(root, ans, k);
        return ans;
    }
};