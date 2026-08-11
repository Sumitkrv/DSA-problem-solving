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
        //vector<int> dp(n+1, 0);
        //dp[0]=dp[1]=1;
        int prev1=1;
        int prev2=1;
        for(int ind=2; ind<=n; ind++){
            int oneStep=prev1;
            int twoStep=prev2;
            int curr=oneStep+twoStep;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;;
    }
};