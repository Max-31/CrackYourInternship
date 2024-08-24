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
    void inorder(TreeNode*node, vector<int>& v, vector<int>&vec){
        if(!node) return;

        inorder(node->left, v, vec);
        v.push_back(node->val);
        vec.push_back(node->val);
        inorder(node->right, v, vec);
    }

    void find(TreeNode* nd, int a, int b){
        queue<TreeNode*>q;
        q.push(nd);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();

            if(node->val == a) node->val =b;
            else if(node->val ==b) node->val =a;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> v, vec;
        inorder(root, v, vec);
        
        sort(vec.begin(), vec.end());

        int a, b;
        for(int i=0; i<v.size(); i++){
            if(v[i]!=vec[i]) {
                a= v[i];
                b=vec[i];
            }
        }

        find(root, a, b);
    }
};