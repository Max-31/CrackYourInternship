class Solution{
    public:
    int sameChar(string a, string b){
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        
        int i=0;
        int ans=0;
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]) ans++;
        }
        
        return ans;
    }
};