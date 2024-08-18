class Solution {
private:
    vector<bool> v;

public:
    Solution() {
        v.resize(1e6 + 1, false);
    }

    int missingNumber(int arr[], int n) { 
        for(int i=0; i<n; i++){
            if(arr[i]>0 && arr[i]<=1e6){
                v[arr[i]]=true;
            }
        }
        
        for(int i=1; i<v.size(); i++){
            if(!v[i]) return i;
        }
        return 1e6 + 1;
    } 
};