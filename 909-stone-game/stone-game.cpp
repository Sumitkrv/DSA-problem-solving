class Solution {
public:
    int f(int i, int j, vector<int>& piles, vector<vector<int>> &dp){
        if(i==j) return piles[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int left=piles[i]-f(i+1, j, piles, dp);
        int right=piles[j]-f(i, j-1, piles, dp);
        int maxi=max(left, right);
        return dp[i][j]= maxi;
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(0, n-1, piles, dp)>0;
    }
};