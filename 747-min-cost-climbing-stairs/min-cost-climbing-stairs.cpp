class Solution {
public:
    // int f(int ind, vector<int>& cost, vector<int> &dp){
    //     if(ind==0 || ind==1){
    //         return cost[ind];
    //     }
    //     if(dp[ind]!=-1) return dp[ind];
    //     int mini=INT_MAX;
    //     int one_step=cost[ind]+ f(ind-1, cost, dp);
    //     int two_step=cost[ind]+ f(ind-2, cost, dp);
    //     mini=min(mini, min(one_step,two_step));
    //     return dp[ind]= mini;

    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1, 0);
        for(int ind=0; ind<n; ind++){
            if(ind==1|| ind==0){
                dp[ind]=cost[ind];
                continue;
            }
            
            int mini=INT_MAX;
            int one_step=cost[ind]+ dp[ind-1];
            int two_step=cost[ind]+ dp[ind-2];
            mini=min(mini, min(one_step,two_step));
            dp[ind]= mini;
        }

        return min(dp[n-1],dp[n-2]);
    }
};