class NumArray {
    vector<int> seg;
    vector<int> v;

    void build(int ind, int low, int high){
        if(low==high){
            seg[ind]= v[low];
            return;
        }
        int mid= low+(high-low)/2;
        build(2*ind+1, low, mid);
        build(2*ind+2, mid+1, high);

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
    NumArray(vector<int>& v) {
        this->v=v;
        seg.resize(4*v.size()+1);
        build(0, 0, v.size()-1);
    }
    
    int sumRange(int left, int right) {
        return find(0, 0, v.size()-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */