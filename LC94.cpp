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
    void inorder(TreeNode*node, vector<int>&v){
        if(node==NULL)return;

        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }

    void inorder_iterative(TreeNode*root, vector<int>&v){
        
        stack<TreeNode*> s;
        // s.push(root);
        TreeNode* node= root;
        while(1){

            if(node!=NULL){
                s.push(node);
                node= node->left;
            }
            else{
                if(s.empty()==true) break;
                
                node= s.top();
                s.pop();
                v.push_back(node->val);
                node= node->right;
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        //recursive approach
        // inorder(root, ans);

        //iterative approach
        if(root==NULL){
            return ans;
        }
        inorder_iterative(root, ans);

        return ans;
    }
};