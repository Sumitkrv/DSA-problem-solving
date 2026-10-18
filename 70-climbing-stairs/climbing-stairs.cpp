class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        int oneStep=f(n-1, dp);
        int twoStep=f(n-2, dp);
        return dp[n]= oneStep+twoStep;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0]=1, dp[1]=1;
        for(int i=2; i<=n; i++){
            int oneStep=dp[i-1];
            int twoStep=dp[i-2];
            dp[i]= oneStep+twoStep;
        }
        return dp[n];
    }
};