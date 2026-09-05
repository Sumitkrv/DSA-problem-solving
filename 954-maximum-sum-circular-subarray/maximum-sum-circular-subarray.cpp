class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int total = nums[0];

        int currMax = nums[0];
        int maxSum = nums[0];

        int currMin = nums[0];
        int minSum = nums[0];

        for(int i = 1; i < n; i++) {

            total += nums[i];

            // Kadane for maximum
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            // Kadane for minimum
            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);
        }
        if(maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};