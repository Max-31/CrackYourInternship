class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int len= min(a.size(), b.size());
        
        string ans="";
        char c='0';
        for(int i=0; i<len; i++){
            if(a[i]!=b[i]){
                if(c=='1') ans+='0';
                else {
                    ans+= '1';
                    c='0';
                }
            }
            else{
                if(a[i]=='0'){
                    if(c=='0') ans+='0';
                    else {
                        ans+= '1';
                        c='0';
                    }
                }
                else{
                    if(c=='1'){
                        ans+='1';
                    }
                    else{
                        ans+='0';
                        c='1';
                    }
                }
            }
        }

        if(len == a.size()){
            //b
            for(int i=len; i<b.size(); i++){
                if(b[i]!=c){
                    if(b[i]=='0'){//c=1
                        ans+='1';
                        c='0';
                    }
                    else{//b1 c0
                        ans+='1';
                    }
                }
                else{
                    if(b[i]=='0'){
                        ans+='0';
                    }
                    else{
                        ans+='0';
                        c='1';
                    }
                }
            }

            if(c=='1'){
                ans+='1';
            }
        }
        else{
            for(int i=len; i<a.size(); i++){
                if(a[i]!=c){
                    if(a[i]=='0'){//c=1
                        ans+='1';
                        c='0';
                    }
                    else{//b1 c0
                        ans+='1';
                    }
                }
                else{
                    if(a[i]=='0'){
                        ans+='0';
                    }
                    else{
                        ans+='0';
                        c='1';
                    }
                }
            }

            if(c=='1'){
                ans+='1';
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};