class Solution {
  public:
    bool isPossible(int k, vector<int> &v1, vector<int> &v2) {
        sort(v1.begin(), v1.end());
        sort(v2.rbegin(), v2.rend());
        
        int n= v1.size();
        for(int i=0; i<n; i++){
            if(v1[i]+v2[i]<k) return false;
        }
        
        return true;
    }
};