class Solution {
public:
    bool findTarget(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind==0) return (target==nums[ind]);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTake=findTarget(ind-1, target, nums, dp);
        bool take=false;
        if(nums[ind]<=target){
            take=findTarget(ind-1, target-nums[ind], nums, dp);
        }
        return dp[ind][target]= take|notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totSum=0;
        for(int i=0; i<n; i++){
            totSum+=nums[i];
        }
        if(totSum%2) return false;
        int target=totSum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
        return findTarget(n-1, target, nums, dp);
    }
};