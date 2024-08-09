void dfs(int node, vector<int>&visited, vector<int>adj[], vector<int>& ans){
    visited[node]= 1;
    ans.push_back(node);
    
    for (auto it: adj[node]){
        if(visited[it]!=1)
            dfs(it, visited, adj, ans);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    vector<int> ans;
    
    dfs(0, visited, adj, ans);
    
    return ans;
}