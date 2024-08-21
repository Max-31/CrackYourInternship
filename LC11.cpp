class Solution {
public:
    int maxArea(vector<int>& v) {
        int n= v.size();
        int l=0; 
        int r= n-1;

        int area= INT_MIN;

        while(l<=r){
            int w= r - l;
            int h= min(v[r], v[l]);
            area= max(area, h*w);

            if(v[r]<v[l]) r--;
            else l++;
        }

        return area;
    }
};