class Solution {
public:
    int func_1(int n){
        if(n==0){
            return 1;
        }
        if(n<0) return 0;

        int l= func_1(n-1);
        int r= func_1(n-2);

        return l+r;
    }

    int func_2(int n, vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(n<0) return 0;

        if(dp[n]!= -1) return dp[n];

        return dp[n]= func_2(n-1, dp) + func_2(n-2, dp);
    }

    int climbStairs(int n) {
        int a;
        vector<int> dp(n+1, -1);

        // a=func_1(n);
        
        a=func_2(n, dp);

        return a;
    }
};
