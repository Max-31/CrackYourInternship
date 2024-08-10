class Solution {
  public:
    int maxLen(vector<int>& v, int n) {
        vector<int> p(v.size());
        p[0]= v[0];
        
        for(int i=0; i<v.size(); i++)
            p[i]= p[i-1]+v[i];
            
        unordered_map<int, pair<int, int>> m;
        
        int ans= 0;
        for(int i=0; i<v.size(); i++){
            if(p[i]==0) ans= max(ans, i+1);
            
            if(m.find(p[i])==m.end()){
                m[p[i]]= {i, i};
            }
            else{
                m[p[i]].second=i;
            }
        }
        
        for(auto it: m){
            pair<int,int> ind;
            ind= it.second;
            // cout<<it.first<<": ("<<ind.first<<", "<<ind.second<<")\n";
            ans= max(ans, ind.second - ind.first);
        }
        
        return ans;
    }
}