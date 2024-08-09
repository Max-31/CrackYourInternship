class Solution {
public:
    string reverseWords(string s) {
        int start=0, end= s.size()-1;
        while(start<s.size() && s[start]==' ') start++;
        while(end>=0 && s[end]==' ') end--;

        // cout<<start<<"-"<<end<<"\n";

        vector<string> v;
        string st="";
        for(int i=start; i<=end; i++){
            if(s[i]!=' '){
                st+=s[i];
            }
            else{
                v.push_back(st);
                v.push_back(" ");

                int ind= i;
                while(ind<=end && s[ind]==' ') ind++;
                i=ind-1;
                st="";
            }
        }
        v.push_back(st);

        string ans="";
        
        for(int i=v.size()-1; i>=0; i--){
            ans+=v[i];
        }

        return ans;

    }
};