class Solution {
public:
    int f(int ind, vector<int> &nums, vector<int> &dp){
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick= nums[ind]+f(ind-2, nums, dp);
        int notPick=0+f(ind-1, nums, dp);

        return dp[ind]= max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //vector<int> dp(n+1, 0);
        //dp[0]=nums[0];
        int prev=nums[0];
        int prev2=0;
        for(int i=1; i<n; i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int notTake=0+prev;
            int cur=max(take, notTake);
            prev2=prev;
            prev=cur;
        }
        int ans=prev;
        return ans;
    }
};