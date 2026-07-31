class Solution {
public:
    // int f(int ind, vector<int>& nums, vector<int>& dp) {
    //     if (ind == 0) {
    //         return nums[ind];
    //     }
    //     if (ind < 0) {
    //         return 0;
    //     }
    //     if (dp[ind] != -1)
    //         return dp[ind];
    //     int notTake = 0 + f(ind - 1, nums, dp);
    //     int take = 0;
    //     if (ind >= 1) {
    //         take = nums[ind] + f(ind - 2, nums, dp);
    //     }
    //     return dp[ind] = max(take, notTake);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        // dp[0]=0;
         dp[1] = nums[0];
        for (int ind = 1; ind < n; ind++) {
            int notTake = 0 + dp[ind];
            int take = 0;
            if (ind >= 1) {
                take = nums[ind] + dp[ind - 2 + 1];
            }
            dp[ind + 1] = max(take, notTake);
        }
        return dp[n];
    }
};