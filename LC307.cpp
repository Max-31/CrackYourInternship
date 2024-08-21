class NumArray {
    vector<int>seg, v;
    unordered_map<int, int> m;

    void build(int ind, int low, int high, unordered_map<int, int>&m){
        if(low==high){
            seg[ind]= v[low];
            m[low]= ind;
            return;
        }
        int mid= low+(high-low)/2;
        build(2*ind+1, low, mid, m);
        build(2*ind+2, mid+1, high, m);

        seg[ind]= seg[2*ind+1] + seg[2*ind+2];
    }

    int find(int ind, int low, int high, int l, int r){
        if(l<=low && high<=r){
            return seg[ind];
        }
        if(high<l || r<low){
            return 0;
        }

        int mid= low+(high-low)/2;
        int left= find(2*ind + 1, low, mid, l, r);
        int right= find(2*ind + 2, mid+1, high, l, r);

        return left+right;
    }

public:
    NumArray(vector<int>& nums) {
        v= nums;
        seg.resize(4*nums.size()+1);
        build(0, 0, v.size()-1, m);
    }
    
    void update(int index, int val) {
        int segi= m[index];
        int preval= seg[segi];
        seg[segi]= val;

        int diff= val-preval;

        int previ;
        if(segi% 2==0){
            segi= (segi-2)/2;
        }
        else{
            segi= (segi-1)/2;
        }

        while(segi>=0){
            seg[segi]+=diff;

            if(segi % 2==0){
                segi= (segi-2)/2;
            }
            else{
                segi= (segi-1)/2;
            }
        }
    }
    
    int sumRange(int left, int right) {
        return find(0, 0, v.size()-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */