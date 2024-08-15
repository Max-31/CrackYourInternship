class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){

            int sizes= q.size();
            queue<Node*> Q;
            for(int i=0; i<sizes; i++){
                Node* node= q.front();
                q.pop();

                if(!q.empty()) node->next= q.front();
                // else node->next= NULL;

                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }

            q= Q;
            
        }
        return root;
    }
};