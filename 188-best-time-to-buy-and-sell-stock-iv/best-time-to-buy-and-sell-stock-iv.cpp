class Solution {
public:
    int f(int ind, int transNo, int k, vector<int>& prices, vector<vector<int>> &dp){
        int n=prices.size();
        if(ind==n || transNo==2*k){
            return 0;
        }
        if(dp[ind][transNo]!=-1) return dp[ind][transNo];
        int profit=0;
        if(transNo%2==0){
            profit=max(-prices[ind]+f(ind+1,transNo+1, k, prices, dp), 0+f(ind+1, transNo, k, prices, dp));
        }
        else{
            profit=max(prices[ind]+ f(ind+1, transNo+1, k, prices, dp), 0+ f(ind+1, transNo, k, prices, dp));
        }
        return dp[ind][transNo]= profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        for(int ind=n-1; ind>=0; ind--){
            for(int transNo=2*k-1; transNo>=0; transNo--){
                int profit=0;
                if(transNo%2==0){
                    profit=max(-prices[ind]+dp[ind+1][transNo+1], 0+dp[ind+1][transNo]);
                }
                else{
                    profit=max(prices[ind]+ dp[ind+1][transNo+1], 0+ dp[ind+1][transNo]);
                }
                dp[ind][transNo]= profit;
            }
        }
        return dp[0][0];
    }
};