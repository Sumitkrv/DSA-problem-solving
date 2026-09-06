class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int suffix=1;
        int prefix=1;
        for(int i=0; i<nums.size(); i++){
            if(suffix==0) suffix=1;
            if(prefix==0) prefix=1;
            suffix=suffix*nums[i];
            prefix=prefix*nums[n-i-1];
            
            ans=max(ans, max(prefix, suffix));
        }
        return ans;
    }
};