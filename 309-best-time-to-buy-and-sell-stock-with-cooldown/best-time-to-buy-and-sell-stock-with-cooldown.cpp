class Solution {
public:
    int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
        int n=prices.size();
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy]= max(-prices[ind]+ f(ind+1, 0, prices, dp), 0+f(ind+1, 1, prices, dp));
        }
        else{
            return dp[ind][buy]= max(prices[ind]+f(ind+2, 1, prices, dp), 0+f(ind+1, 0, prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //vector<vector<int>> dp(n+2, vector<int>(2, 0));
        vector<int>next2 (2, 0);
        vector<int>next1 (2, 0);
        vector<int>cur (2, 0);


        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                if(buy){
                    cur[buy]= max(-prices[ind]+ next1[0], 0+next1[1]);
                }
                else{
                    cur[buy]= max(prices[ind]+next2[1], 0+next1[0]);
                }
            }
            next2=next1;
            next1=cur;
        }

        return next1[1];
    }
};