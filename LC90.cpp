class Solution {
    void helper(int ind, vector<int>&v, vector<int>&ds, set<vector<int>>&ans){
        ans.insert(ds);
        if(ind==v.size()){
            return;
        }

        for(int i=ind; i<v.size(); i++){
            ds.push_back(v[i]);
            helper(i+1, v, ds, ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int>ds;
        
        helper(0, nums, ds, ans);

        vector<vector<int>>res;
        for(auto it= ans.begin(); it!=ans.end(); it++){
            res.push_back(*it);
        }

        return res;
    }
};