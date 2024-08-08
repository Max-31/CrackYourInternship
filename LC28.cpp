class Solution {
public:
    int strStr(string txt, string pat) {
        vector<int> lps(pat.size());
        lps[0]=0;
        int len = 0;

        int i=0, j=1;
        while(j<pat.size()){
            if(pat[i]==pat[j]){
                i++;
                lps[j]= i;
                j++;
            }
            else{
                if(i!=0){
                    i= lps[i-1];
                }
                else{
                    lps[j]=0;
                    j++;
                }
            }
        }
        // print(lps);

        i=0;
        // int j=0;
        j=0;

        while(j<txt.size()){
            if(txt[j] == pat[i]){
                if(i==pat.size()-1){
                    //matched
                    j++;
                    return j-(pat.size());
                }
                i++;
            }
            else{
                if(i>0){
                    i--;
                    i=lps[i];
                    j--;
                }
            }
            j++;
        }
        
        return -1;
    }
};