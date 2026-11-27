class Solution {
public:
    // int maxi(int ind, vector<int> &temp, vector<int> &dp){
    //     if(ind==0) return temp[0];
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int take=temp[ind]+ maxi(ind-2, temp, dp);
    //     int notTake=0+ maxi(ind-1, temp, dp);
    //     return dp[ind]= max(take, notTake);
    // }
    int f(vector<int> &temp){
        int n=temp.size();
        //vector<int> dp(n+1, 0);
        int prev=temp[0];
        int prev2=0;
        for(int i=1; i<n; i++){
            int take=temp[i];
            if(i>1) take+=prev2;
            int notTake=0+prev;
            int cur=max(take, notTake);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(f(temp1), f(temp2));
    }
};