class Solution {
public:
    int maximumProduct(vector<int>& v) {
        if(v.size()==3) return v[0]*v[1]*v[2];
        
        sort(v.begin(), v.end());

        int case1=0, case2=0, case3=0;
        int n= v.size();

        if(v[0]<0 && v[1]<0){
            case1= v[0]*v[1]*v[n-1];
        }

        case2= v[n-1]*v[n-2]*v[n-3];

        return max(case1, case2);
        
    }
};