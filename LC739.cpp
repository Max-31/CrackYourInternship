class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        stack<int> s;
        vector<int> ans(v.size());

        for(int i=0; i<v.size(); i++){
            if(s.empty()){
                s.push(i);
            }
            else{
                if(v[i]<=v[s.top()]){
                    s.push(i);
                }
                else{
                    while(!s.empty() && (v[i]>v[s.top()])){
                        int ind= s.top();
                        s.pop();
                        ans[ind]= i-ind;
                    }
                    s.push(i);
                }
            }
        } 
        while(!s.empty()){
            int ind= s.top();
            s.pop();
            ans[ind]= 0;
        }

        return ans;
    }
};