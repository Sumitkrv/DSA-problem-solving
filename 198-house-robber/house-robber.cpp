class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int> &dp){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int nonPick=0+f(ind-1, nums, dp);
        int pick=nums[ind]+ f(ind-2, nums, dp);
        return dp[ind]= max(pick, nonPick);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //vector<int> dp(n, 0);
        //dp[0]=nums[0];
        int prev=nums[0];
        int prev2=0;
        for(int ind=1; ind<n; ind++){
            int nonPick=0+prev;
            int pick=nums[ind];
            if(ind>1){
                pick+=prev2;
            }
            int curr= max(pick, nonPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};