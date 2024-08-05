vector<long long int> productExceptSelf(vector<long long int>& v) {
        vector<long long int> ans(v.size());
        long long int p=1, pr=1;
        bool f= false;
        int zero=0;
        
        for(int i=0; i<v.size(); i++){
            p*=v[i];
            
            if(v[i]!=0) pr*= v[i];
            
            if(v[i]==0) zero++;
            if(zero>1) f=true;
        }
        
        if(p==0) {
            vector<long long int> ans1(v.size(), 0);
            if(f) return ans1;
            
            for(int i=0; i<v.size(); i++){
                if(v[i]==0) ans1[i]= pr;
            }
            
            return ans1;
        }
        
        for(int i=0; i<v.size(); i++){
            ans[i]= p/v[i];
        }
        
        return ans;
    }