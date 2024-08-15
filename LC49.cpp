class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n= s.size();
        if(n==0){
            return {{""}};
        }
        if(n==1){
            return {{s[0]}};
        }

        map<vector<int>, vector<string>> m;
        vector<vector<string>> ans;

        for(int i=0; i<n; i++){
            vector<int> alpha (26, 0);

            for(int j=0; j<s[i].length(); j++){
                alpha[s[i][j]-'a']++;
            }

            m[alpha].push_back(s[i]);

        }

        for(auto it: m){
            ans.push_back(it.second);
        }

        return ans;
    }
};