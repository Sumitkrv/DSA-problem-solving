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
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};