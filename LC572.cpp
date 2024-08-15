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
    bool inorder(TreeNode* node1, TreeNode* node2){
        if(node1==NULL || node2==NULL){
            return node1==node2;
        }

        if(node1->val != node2->val) return false;

        bool leftie= inorder(node1->left, node2->left);
        bool rightie= inorder(node1->right, node2->right);

        return leftie & rightie;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL  || subRoot==NULL ){
            return root==subRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();

            bool ans= false;

            if(node->val== subRoot->val){
                cout<<node->val;
                ans= inorder(node, subRoot);
                // break;
            }

            if(ans) return ans;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return false;
    }
};