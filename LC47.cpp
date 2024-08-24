class Solution {
    void helper(int ind, vector<int>&v, set<vector<int>>&ans){
        if(ind==v.size()) return;

        for(int i=ind; i<v.size(); i++){
            swap(v[ind], v[i]);
            ans.insert(v);
            helper(ind+1, v, ans);
            swap(v[ind], v[i]);
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        helper(0, nums, res);

        vector<vector<int>> ans;
        for(auto it=res.begin(); it!=res.end(); it++){
            ans.push_back(*it);
        }

        return ans;
    }
};