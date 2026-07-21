class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0; i<n; i++){
            int mask=0;
            for(int j=i; j<n; j++){
                if(mask &nums[j] ) break;

                mask|=nums[j];
                ans=max(ans, j-i+1);
            }
        }
        return ans;
    }
};