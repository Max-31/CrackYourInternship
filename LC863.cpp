/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void parentptr(TreeNode*node, unordered_map<TreeNode*, TreeNode*>&m){
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()){

            TreeNode* node= q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                m[node->left]= node;
            }
            if(node->right){
                q.push(node->right);
                m[node->right]= node;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parentm;
        parentptr(root, parentm);

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node= q.front();
            q.pop();

            if(node == target){
                queue<TreeNode*> Q;
                Q.push(node);
                int cnt=0;
                vector<int>visited(501, 0);
                visited[node->val]=1;

                while(!Q.empty() && k--){
                    int sizes= Q.size();
                    // if(k--) break;
                    for(int i=0; i<sizes; i++){

                        TreeNode* node1= Q.front();
                        Q.pop();

                        if(node1->left && !visited[node1->left->val]){
                            Q.push(node1->left);
                            visited[node1->left->val]=1;
                        }
                        if(node1->right && !visited[node1->right->val]){
                            Q.push(node1->right);
                            visited[node1->right->val]=1;
                        }
                        if(node1!=root && !visited[parentm[node1]->val]){
                            Q.push(parentm[node1]);                        
                            visited[parentm[node1]->val]=1;
                        }
                    }
                }

                vector<int> ans;
                while(!Q.empty()){
                    ans.push_back(Q.front()->val);
                    Q.pop();
                }
                return ans;

            }
            else{
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return {};
    }
};