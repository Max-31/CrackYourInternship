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
    void inorder(TreeNode* node, vector<int>&ds, vector<vector<int>>&ans){
        if(node==NULL) return;
        if(node->left==NULL && node->right==NULL){
            ds.push_back(node->val);
            ans.push_back(ds);
            ds.pop_back();
        }

        ds.push_back(node->val);
        inorder(node->left, ds, ans);
        inorder(node->right, ds, ans);
        ds.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int> ds;
        inorder(root, ds, ans);

        vector<string> res;

        for(int i=0; i<ans.size(); i++){
            string s="";
            for(int j=0; j<ans[i].size(); j++) {
                int num= ans[i][j];
                s+= to_string(num);
                if(j!=ans[i].size()-1)
                    s+="->";
            }
            res.push_back(s);
        }

        return res;
    }
};