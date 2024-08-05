int findFloor(vector<long long> &v, long long n, long long x) {

    vector<long long>::iterator l;
    l= lower_bound(v.begin(), v.end(), x);
    
    int ind= l-v.begin();
    
    if(v[ind] != x) return ind-1;
    
    return ind;
}