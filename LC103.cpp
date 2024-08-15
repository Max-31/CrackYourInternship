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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int f=1;
        vector<int>vec;
        while(!q.empty()){
            int sizes= q.size();
            if(f==1) f=0;
            else f=1;

            for(int i=0; i<sizes; i++){
                TreeNode* node= q.front();
                q.pop();
                vec.push_back(node->val);
                cout<<node->val<<" ";

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            cout<<endl;
            if(f) reverse(vec.begin(), vec.end());
            ans.push_back(vec);

            vec.clear();
        }

        return ans;
    }
};