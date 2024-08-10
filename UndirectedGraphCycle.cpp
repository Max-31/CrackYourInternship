class Solution {
    bool dfs(int i, int parent, vector<int>&visited, vector<int>adj[]){
        
        visited[i]=1;
        
        for(auto it: adj[i]){
            if(visited[it]!=1){
                if(dfs(it, i, visited, adj)==true)
                    return true;
            }
            else if(parent != it){
                return true;
            }
        }
        
        return false;
    }
  
  public:
  
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        
        for(int i=0; i<V; i++){
            if(visited[i]!=1){
                if(dfs(i, -1, visited, adj)==true)
                    return true;
            }
        }
        return false;
    }
};