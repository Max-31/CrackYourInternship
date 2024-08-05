class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>&v2, int n) {
        vector<int> v;
        int i=0, j=0;

        while(i<m && j<n){
            if(v1[i]<=v2[j]){
                v.push_back(v1[i]);
                i++;
            }
            else{
                v.push_back(v2[j]);
                j++;
            }
        }
        while(i<m){
            v.push_back(v1[i]);
            i++;
        }
        while(j<n){
            v.push_back(v2[j]);
            j++;
        }

        v1.clear();
        v1= v;
    }
};