class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n= v.size();

        int sum1= accumulate(v.begin(), v.begin()+k, 0);
        int sum2= accumulate(v.end()-k, v.end(), 0);

        int sum=0, sum3=0;
        int i=0, j=n-k+1;
        for(int ind=j; ind<n; ind++) sum+=v[ind];
        sum+=v[i];

        while(j<n){
            cout<<sum<<endl;
            sum3= max(sum, sum3);

            sum-=v[j]; j++;
            i++; sum+=v[i];
        }
        
        // return sum3;
        return max(sum1, max(sum2, sum3));
    }
};