class Solution {
public:
    int kthSmallest(vector<vector<int>>& v, int k) {
        int n = v.size(), m = v[0].size(); 

        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq.push(v[i][j]);

                if (pq.size() > k) pq.pop();
            }
        }
        
        //IMPORTANT: Priority queue te DUPLICATES to dhoke

        // while(!pq.empty()) { 
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        // }
        return pq.top();
        // return 0;
    }
};