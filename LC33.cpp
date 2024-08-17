class Solution {
public:
    int search(vector<int>&v, int t) {
        int n= v.size();
        int l=0, h=n-1;

        while(l<=h){
            int m= l+(h-l)/2;

            if(v[m]==t){
                return m;
            }

            if(v[l]<=v[m] && v[m]<=v[h]){
                if(v[m]<t) l= m+1;
                else h=m-1;
            }
            else{
                if(v[l]<=v[m]){
                    if(v[l]<= t && t<=v[m]){
                        h=m-1;
                    }
                    else{
                        l=m+1;
                    }
                }
                else{
                    if(v[m]<= t && t<=v[h]){
                        l=m+1;
                    }
                    else{
                        h=m-1;
                    }
                }
            }
        }

        return -1;
    }
};