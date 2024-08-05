class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        int i=0;
        int n= 300;
        for(int i=0; i<v.size(); i++){
            if(n>v[i].size()){
                n= v[i].size();
            }
        }

        string ans="";

        for(int i=0; i<n; i++){
            char c= v[0][i];
            bool f= true;

            for(int j=1; j<v.size(); j++){
                if(c!=v[j][i]){
                    f=false;
                    break;
                }
            }

            if(f==true){
                ans+= c;
            }
            else break;
        }

        return ans;
    }
};