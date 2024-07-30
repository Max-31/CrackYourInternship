class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {
        int n= v.size();
        vector<int> f(n+1, 0), ans;

        for(int i=0; i<n; i++){
            f[v[i]]++;

            if(f[v[i]]==2){
                ans.push_back(v[i]);
            }
        }

        return ans;
    }
};