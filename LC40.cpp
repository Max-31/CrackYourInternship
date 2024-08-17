class Solution {
public:
    void func(int ind, int t, vector<int>&ds, vector<int>&v, vector<vector<int>>&ans){
        if(t==0){
            ans.push_back(ds);
            return;
        }

        for(int i=ind; i<v.size(); i++){
            if(t<v[i]) break;

            if(i>ind && v[i]==v[i-1]) continue;

            ds.push_back(v[i]);
            func(i+1, t-v[i], ds, v, ans);
            ds.pop_back();

        }
        // return;
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        sort(v.begin(), v.end());
        vector<int> ds;
        vector<vector<int>>ans;
        func(0, t, ds, v, ans);

        return ans;
    }
};