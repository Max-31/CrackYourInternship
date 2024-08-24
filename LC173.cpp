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
class BSTIterator {
    vector<int> v;
    int ind;
    TreeNode* node;
public:
    BSTIterator(TreeNode* root) {
        ind=0;
        node= root;
        inorder(node, v);
        // v.clear();
    }

    void inorder(TreeNode* node, vector<int>&v){
        if(!node) return ;

        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
    
    int next() {
        int ans= v[ind];
        ind++;
        return ans;
    }
    
    bool hasNext() {
        if(ind>v.size()-1) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */