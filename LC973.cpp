class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pnt, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>pq;
        for(int i=0; i<pnt.size(); i++){
            int x=pnt[i][0], y=pnt[i][1];
            double dist= sqrt(x*x + y*y);

            pq.push({dist, i});
        }

        vector<vector<int>> ans;
        while(k--){
            int ind= pq.top().second;
            ans.push_back(pnt[ind]);
            pq.pop();
        }
        
        return ans;
    }
};