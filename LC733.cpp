class Solution {
    void dfs(int i, int j, vector<vector<int>>&visited, vector<vector<int>>& v, int sr, int sc, int colour, int prevcolour){
        if(i<0 || j<0 || i>v.size()-1 || j>v[0].size()-1 || prevcolour!= v[i][j] || visited[i][j]==1){
            return;
        }

        visited[i][j]=1;
        // if(i!=sr && j!=sc)
        v[i][j]= colour;

        dfs(i+1, j, visited, v, sr, sc, colour, prevcolour);
        dfs(i-1, j, visited, v, sr, sc, colour, prevcolour);
        dfs(i, j+1, visited, v, sr, sc, colour, prevcolour);
        dfs(i, j-1, visited, v, sr, sc, colour, prevcolour);

    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int color) {
        vector<vector<int>>visited(v.size(), vector<int>(v[0].size(), 0));

        dfs(sr, sc, visited, v, sr, sc, color, v[sr][sc]);

        // v[sr][sc]= color;
    
        return v;
    }
};