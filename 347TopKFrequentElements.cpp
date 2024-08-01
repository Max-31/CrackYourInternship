class Solution {
public:

    void showpq(priority_queue<pair<int,int>> g){
        while (!g.empty()) {
            cout << "\n" << g.top().second<<"-"<<g.top().first;
            g.pop();
        }
        cout << "\n";
    }

    vector<int> topKFrequent(vector<int>& v, int k) {
        int n=v.size();
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            m[v[i]]++;
        }

        priority_queue<pair<int,int>> p;
        for(auto it:m){
            pair<int, int> pr;
            pr.first= it.second;
            pr.second= it.first;
            p.push(pr);
        }
        showpq(p);
        vector<int>ans;
        while(!p.empty() && k>0){
            ans.push_back(p.top().second);
            k--;
            p.pop();
        }

        return ans;
    }
};