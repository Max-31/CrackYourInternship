class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n= v.size();
        vector<int>f(n+1,0);

        for(int i=0; i<n; i++){
            f[v[i]]++;
            if(f[v[i]]==2) return v[i];
        }

        return -1;
    }
};