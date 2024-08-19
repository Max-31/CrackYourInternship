class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& v) {
        unordered_set<int> s;
        for(int i=0; i<v.size(); i++){
            int f=0;
            for(int j=0; j<v[i].size(); j++){
                if(v[i][j]!=0){
                    f=1;
                    break;
                }
            }
            
            if(f==0){
                s.insert(i);
            }
        }
        
        int ans=-1;
        
        for(auto it= s.begin(); it!=s.end(); it++){
            int row= *it;
            int f=1;
            for(int i=0; i<v.size(); i++){
                if(row!=i && v[i][row]!=1){
                    f=0;
                    break;
                }
            }
            
            if(f==1){
                ans= row;
                break;
            }
        }
        
        return ans;
    }
};