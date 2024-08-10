class Solution {
    void helper(int i, int j, string ds, vector<vector<int>>&visited, vector<vector<int>>&v, vector<string>&ans){
        if(i==v.size()-1 && j==v[0].size()-1){
            ans.push_back(ds);
            return;
        }
        if(i<0 || j<0 || i>v.size()-1  || j>v[0].size()-1 || v[i][j] == 0 || visited[i][j] == 1)
            return;
        
        visited[i][j] = 1;
        
        if(!(i+1>v.size()-1) && v[i+1][j] == 1 && visited[i+1][j]==0){
            helper(i+1,j, ds+'D', visited, v, ans);
        } 
        
        if(!(i-1<0) && v[i-1][j] == 1 && visited[i-1][j]==0){
            helper(i-1,j, ds+'U', visited, v, ans);
        }
        
        if(!(j+1>v[0].size()-1) && v[i][j+1] == 1 && visited[i][j+1]==0) {
            helper(i,j+1, ds+'R', visited, v, ans);
        }
        
        if(!(j-1<0) && v[i][j-1] == 1 && visited[i][j-1]==0) {
            helper(i,j-1, ds+'L', visited, v, ans);
        }
        
        visited[i][j] = 0;
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &v) {
        vector<vector<int>>visited(v.size(), vector<int>(v[0].size(), 0));
        vector<string> ans;
        
        if(v[0][0]==0) return ans;
        
        helper(0,0,"", visited, v, ans);
        
        return ans;
    }
};