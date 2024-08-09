class Solution {
    void helper(vector<int> &v, int ind, int n, set<vector<int>>&s){
        if(ind == n){
            s.insert(v);
            return;
        }
        
        for(int i=ind; i<n; i++){
            swap(v[ind], v[i]);
            helper(v, ind+1, n, s);
            swap(v[ind], v[i]);
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &v ,int n) {
        set<vector<int> > s;
        
        helper(v, 0, n, s);
        
        vector<vector<int>>ans(s.begin(), s.end());
        
        return ans;
        
    }
};