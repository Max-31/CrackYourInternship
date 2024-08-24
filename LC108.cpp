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
    TreeNode* helper(int low, int high, vector<int>&v ){
        if(low==high){
            TreeNode* nd= new TreeNode(v[low]);
            return nd;
        }
        else if(low>high) return NULL;

        int mid= low + (high-low)/2;
        TreeNode* root= new TreeNode(v[mid]);
        root->left= helper(low, mid-1, v);
        root->right= helper(mid+1, high, v);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& v) {
        return helper(0, v.size()-1, v);
    }
};