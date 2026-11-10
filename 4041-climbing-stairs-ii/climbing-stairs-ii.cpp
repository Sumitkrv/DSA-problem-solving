class Solution {
public:
    int f(int ind, vector<int> &costs, vector<int> &dp){
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int oneStep=INT_MAX;
        int twoStep=INT_MAX;
        int threeStep=INT_MAX;
        if(ind>=1) oneStep= costs[ind-1]+1+ f(ind-1, costs, dp);
        if(ind>=2) twoStep= costs[ind-1]+4+ f(ind-2, costs, dp);
        if(ind>=3) threeStep= costs[ind-1]+9+ f(ind-3, costs, dp);
        return dp[ind]= min(oneStep, min(twoStep, threeStep));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return f(n, costs, dp);
    }
};