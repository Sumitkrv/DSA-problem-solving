class Solution {
public:
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(row==0 && col==0){
            return grid[0][0];
        }
        if(row<0 || col<0){
            return 1e9;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int up=grid[row][col] +f(row-1, col, grid, dp);
        int left=grid[row][col] +f(row, col-1, grid, dp);

        return dp[row][col]= min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, grid, dp);
    }
};