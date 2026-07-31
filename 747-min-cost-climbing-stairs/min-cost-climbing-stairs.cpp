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
       // vector<int> dp(n, 0);
        int prev=cost[1];
        int prev2=cost[0];
        for(int ind=2; ind<n; ind++){
            int mini=INT_MAX;
            int one_step=cost[ind]+ prev;
            int two_step=cost[ind]+ prev2;
            mini=min(mini, min(one_step,two_step));
            int cur= mini;
            prev2=prev;
            prev=cur;
        }

        return min(prev, prev2);
    }
};