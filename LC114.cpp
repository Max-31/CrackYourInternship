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
    void preorder(TreeNode* node, vector<int>& trav){
        if(!node) return;

        trav.push_back(node->val);

        preorder(node->left, trav);
        preorder(node->right, trav);
    }
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        vector<int> trav;
        preorder(root, trav);

        TreeNode* ptr= root;

        for(int i=1; i<trav.size(); i++){
            if(ptr->right) {
                // cout<<ptr->right->val<<": ";

                ptr->right->val= trav[i];
                ptr->left= NULL;
                // cout<<ptr->right->val<<endl;

                ptr=ptr->right;
            }
            else {
                cout<<ptr->val<<endl;
                ptr->right= new TreeNode(trav[i]);

                ptr->left= NULL;
                ptr= ptr->right;
            }

        }
    }
};