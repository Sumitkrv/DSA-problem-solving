class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int mask=0;
        int ans=0;
        for(int right=0; right<n; right++){
            while(nums[right] & mask){
                mask^=nums[left];
                left++;
            }
            mask|=nums[right];
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};