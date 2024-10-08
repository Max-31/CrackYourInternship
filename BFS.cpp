vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    
    vector<int> visited (V, 0);
    
    queue<int> q;
    q.push(0);
    visited[0]=1;
    
    while(!q.empty()){
        int node= q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(visited[it] != 1){
                q.push(it);
                visited[it]=1;
            }
        }
    }
    
    return ans;
}