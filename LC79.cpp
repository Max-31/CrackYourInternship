class Solution {
    void dfs(int i, int j, bool &ans, string ds, int ind, string term, vector<vector<int>>&visited, vector<vector<char>>&v){
        
        // cout<<ds<<"\n";
        if(ds == term){
            ans= true;
            return;
        }
        if(i<0 || j<0 || i>v.size()-1  || j>v[0].size()-1 || visited[i][j] == 1) 
            return;
        if(v[i][j] != term[ind])
            return;
        if(ds.size() > term.size())
            return;

        visited[i][j]=1;


        dfs(i+1,j, ans, ds+v[i][j], ind+1, term, visited, v);
        dfs(i-1,j, ans, ds+v[i][j], ind+1, term, visited, v);
        dfs(i,j+1, ans, ds+v[i][j], ind+1, term, visited, v);
        dfs(i,j-1, ans, ds+v[i][j], ind+1, term, visited, v);        

        visited[i][j]=0;

        // return a|(b|(c|d));
    }
public:
    bool exist(vector<vector<char>>& v, string term) {
        vector<vector<int>> visited(v.size(), vector<int>(v[0].size(), 0));
        bool ans= false;
        int ind=0;

        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[0].size(); j++){
                if(v[i][j]==term[ind]){
                    // cout<<v[i][j]<<"\n";
                    dfs(i, j, ans, "", ind, term, visited, v);
                }
                
                if(ans==true){
                    return ans;
                }

            }
        }
        return ans;
    }
};