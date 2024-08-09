class Solution {
    void markbydfs(int x, int y, vector<vector<char>>& v){
        if(x<0 || y<0 || x>v.size()-1 || y>v[0].size()-1 || v[x][y]!='1')
            return;

        v[x][y]= '2';

        markbydfs(x+1, y, v);
        markbydfs(x-1, y, v);
        markbydfs(x, y+1, v);
        markbydfs(x, y-1, v);
    }
public:
    int numIslands(vector<vector<char>>& v) {
        int ans=0;
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[0].size(); j++){
                if(v[i][j]=='1'){
                    ans++;
                    markbydfs(i, j, v);
                }
            }
        }

        return ans;
    }
};