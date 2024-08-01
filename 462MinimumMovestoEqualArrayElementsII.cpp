class Solution {
public:
    int minMoves2(vector<int>& v) {
        sort(v.begin(), v.end());
        int ind= v.size()/2;

        int ans=0;
        for(int i=0; i<v.size(); i++){
            ans+= abs(v[i]-v[ind]);
        }

        return ans;
    }
};