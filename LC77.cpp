class Solution {
    void helper(int i, int k, vector<int>&v, vector<int>&ds, vector<vector<int>>&ans){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(i==v.size()){
            return;
        }

        ds.push_back(v[i]);
        helper(i+1, k, v, ds, ans);
        ds.pop_back();

        helper(i+1, k, v, ds, ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds, v;

        for(int i=1; i<=n; i++) v.push_back(i);

        helper(0, k, v, ds, ans);

        return ans;
    }
};