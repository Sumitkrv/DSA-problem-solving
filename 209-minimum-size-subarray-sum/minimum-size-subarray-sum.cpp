class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int left=0, right=0;
        int len=INT_MAX;
        int sum=0;
        while(right<n || sum>=target){
            
            if(sum<target){
                sum+=nums[right];
                right++;
            }
            else{
                
                while(sum>=target){
                    len=min(len, right-left);
                    sum-=nums[left];
                    left++;
                    
                }
            }

        }
        return len==INT_MAX ?0 : len;;
    }
};