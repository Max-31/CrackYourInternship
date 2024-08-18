class Solution {
    bool find(int i, vector<int>&v, int num){
        int l=i, h=v.size()-1;
        
        while(l<=h){
            int m=l+(h-l)/2;
            
            if(v[m]==num) return true;
            
            if(v[m]<num) l=m+1;
            else h=m-1;
        }
        
        return false;
    }
    
  public:
    int findPair(int n, int x, vector<int> &v) {
        sort(v.begin(), v.end());
        
        for(int i=0; i<n-1; i++){
            int num= v[i]+x;
            
            if(find(i+1, v, num)){
                return 1;
            }
        }
        
        return -1;
    }
};