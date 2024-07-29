class Solution {
    pair<int , int> lowfirst(vector<int>&v, int low, int high){
        int ind=0;

        for(int i=0; i<v.size()-1; i++){
            if(v[i]<v[i+1]){
                if(low> v[i]){
                    low= v[i];
                    ind= i;
                }
            }
        }

        int diff=0;
        for(int i=ind+1; i<v.size(); i++){
            if(diff<v[i]-v[ind]){
                diff= v[i]-v[ind];
                high= v[i];
                // cout<<diff<<"= "<<v[i]<<"-"<<v[ind]<<endl;
            }
        }

        return {low, high};
    }

    pair<int , int> highfirst(vector<int>&v, int low, int high){
        int ind=0;

        for(int i=0; i<v.size()-1; i++){
            if(v[i]<v[i+1]){
                if(high< v[i+1]){
                    high= v[i+1];
                    ind= i+1;
                }
            }
        }

        int diff=0;
        for(int i=0; i<ind; i++){
            if(diff < v[ind]- v[i]){
                diff= v[ind]- v[i];
                // cout<<diff<<"= "<<v[ind]<<"-"<<v[i]<<endl;
                low= v[i];
            }
        }

        return {low, high};
    }

public:
    int maxProfit(vector<int>& v) {
        int mini= *min_element(v.begin(), v.end());
        int maxi= *max_element(v.begin(), v.end());
        int low= maxi; 
        int high= mini; 
        
        cout<<"low first:\n";
        pair<int, int> low1= lowfirst(v, low, high);
        cout<<"high first:\n";
        pair<int, int> low2= highfirst(v, low, high);

        int l1= low1.first, h1= low1.second;
        int l2= low2.first, h2= low2.second;

        cout<<l1<<"-"<<h1<<" & "<<l2<<"-"<<h2;

        if((l1== maxi && h1==mini)&&(l1==l2 && h1==h2)){
            return 0;
        }
        return max((h1-l1), (h2-l2));
    }
};