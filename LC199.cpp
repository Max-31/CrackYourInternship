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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};

        map<int, int> m;
        vector<int> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});

        while(!q.empty()){
            TreeNode* node= q.front().first;
            pair<int,int> coordinate= q.front().second;
            int x= coordinate.first, y= coordinate.second;
            q.pop();

            //debugg line
            cout<<node->val<<": ("<<x<<", "<<y<<")\n";

            if(node) m[y]= node->val;

            if(node->left){
                q.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                q.push({node->right, {x+1, y+1}});
            }
        }

        for(auto it:m){
            ans.push_back(it.second);
        }

        return ans;
    }
};