class Solution {
public:
    int f(int ind, vector<int> &dp){
        if(ind<=1) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int oneStep=f(ind-1, dp);
        int twoStep=f(ind-2, dp);
        return dp[ind]=oneStep+twoStep;
    }
    int climbStairs(int n) {
        if(n<=1) return 1;
        vector<int> dp(n+1, 0);
        dp[0]=dp[1]=1;
        for(int ind=2; ind<=n; ind++){
            int oneStep=dp[ind-1];
            int twoStep=dp[ind-2];
            dp[ind]=oneStep+twoStep;
        }
        return dp[n];
    }
};