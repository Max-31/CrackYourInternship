class Solution{
    void parentmark(Node*root, unordered_map<Node*, Node*>&m, unordered_map<Node*, bool>&vis){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node= q.front();
            q.pop();
            
            vis[node]= false;
            
            if(node->left){
                m[node->left]= node;
                q.push(node->left);
            }
            if(node->right){
                m[node->right]= node;
                q.push(node->right);
            }
        }
    }
    
    Node* find(Node* root, int target){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node= q.front();
            q.pop();
            
            if(node->data == target) return node;
            
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        return NULL;
    }
    
    int bfs(Node* src, Node*dst, unordered_map<Node*, Node*>&m, unordered_map<Node*, bool>&visited){
        queue<Node*> q;
        q.push(src);
        int ans=0;
        while(!q.empty()){
            ans++;
            int sizes= q.size();
            
            for(int i=0; i<sizes; i++){
                Node* node= q.front();
                q.pop();
                
                if(node==dst) return ans;
                
                if(node->left){
                    if(!visited[node->left]){
                        q.push(node->left);
                        visited[node->left] =true;
                    }
                }
                if(node->right){
                    if(!visited[node->right]){
                        q.push(node->right);
                        visited[node->right] =true;
                    }
                }
                if(m[node]!=NULL){
                    Node* pnode= m[node];
                    if(!visited[pnode]){
                        q.push(pnode);
                        visited[pnode] =true;
                    }
                }
            }
        }
        
        return -1;
        
    }
    
    public:
    
    int findDist(Node* root, int a, int b) {
        unordered_map<Node*, Node*> m;
        unordered_map<Node*, bool> visited;
        
        Node* src= find(root, a);
        Node* dst= find(root, b);
        
        m[root]=NULL;
        parentmark(root, m, visited);
        
        return bfs(src, dst, m, visited)-1;
        
    }
};