class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& s) {
        int n= s.size();
        
        map<string, vector<string>> m;
        for(int i=0; i<s.size(); i++){
            string str= s[i];
            sort(str.begin(), str.end());
            m[str].push_back(s[i]);
        }
        
        vector<vector<string>> ans;
        for(auto it: m){
            vector<string> v(it.second.begin(), it.second.end());
            
            ans.push_back(v);
        }
        
        return ans;
    }
};