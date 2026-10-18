class Solution {
public:
    int f(int ind, vector<int>& cost, vector<int> &dp){
        if(ind==1 || ind==0){
            return cost[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        int mini=INT_MAX;
        int oneStep=cost[ind]+ f(ind-1, cost, dp);
        int twoStep=cost[ind]+ f(ind-2, cost, dp);
        mini=min(mini, min(oneStep, twoStep));
        return dp[ind]= mini;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //int minCost=cost[n-1];
        vector<int> dp(n+1, -1);
        return min(f(n-1, cost, dp), f(n-2, cost, dp));
    }
};