class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int h= v.size()-1, l=0;

        int ind=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]!=0){
                swap(v[ind], v[i]);
                ind++;
            }
        }

    }
};