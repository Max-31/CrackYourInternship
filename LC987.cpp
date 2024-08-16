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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, multiset<int>>>m;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            TreeNode* node= q.front().first;
            pair<int,int> loc= q.front().second;
            int x= loc.first;
            int y= loc.second;
            q.pop();

            m[y][x].insert(node->val); 

            if(node->left) q.push({node->left, {x+1, y-1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
        }

        vector<vector<int>> ans;

        for(auto it:m){
            map<int, multiset<int>> m1= it.second;
            vector<int> v;
            for(auto i: m1){
                // set<int> s=i.second;
                for(auto ind= i.second.begin(); ind!=i.second.end(); ind++){
                    v.push_back(*ind);
                }
            }
            ans.push_back(v);
        }

        return ans;
    }
};