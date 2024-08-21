class Solution {
int check(vector<vector<int>>& v, int i, int j){
    int cnt=0;

    int top=0, bottom=0, left=0, right=0, topleft=0, topright=0, bottomleft=0, bottomright=0; 

    if((0<=i-1) && v[i-1][j]) top++;
    if((i+1<=v.size()-1) && v[i+1][j]) bottom++;
    if((0<=j-1) && v[i][j-1]) left++;
    if((j+1<=v[i].size()-1) && v[i][j+1]) right++;

    if((0<=i-1 && 0<=j-1) && v[i-1][j-1]) topleft++;
    if((0<=i-1 && j+1<=v[i].size()-1) && v[i-1][j+1]) topright++;
    if((i+1<=v.size()-1 && 0<=j-1) && v[i+1][j-1]) bottomleft++;
    if((i+1<=v.size()-1 && j+1<=v[i].size()-1) && v[i+1][j+1]) bottomright++; 

    return top+bottom+left+right+topleft+topright+bottomleft+bottomright;
}
public:
    void gameOfLife(vector<vector<int>>& v) {
        map<int, map<int, int>> m;

        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].size(); j++){
                int a= check(v, i, j);

                m[i][j]= v[i][j];

                if(v[i][j]==1){
                    if(a<2 || a>3){
                        m[i][j]=0;
                    }
                }
                else{
                    if(a==3){
                        m[i][j]=1;
                    }
                }
                
            }
        }

        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].size(); j++){
                v[i][j]= m[i][j];
                
            }
        }
    }
};