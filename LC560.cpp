class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        vector<int> p(v.size());
        p[0]=v[0];
        for(int i=1; i<v.size(); i++) p[i]= p[i-1]+v[i];

        unordered_map<int, int> m;
        int ans=0;
        for(int i=0; i<p.size(); i++){
            if(p[i]==k){
                ans++;
            }

            if(m.find(p[i]-k) != m.end()){
                ans+= m[p[i]-k];
            }

            m[p[i]]++;
        }

        return ans;
    }
};