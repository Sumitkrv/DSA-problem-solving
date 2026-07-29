class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int totSum=(n*(n+1))/2;
        int duplicate;
        int sum=0;
        vector<int> ans;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]){
                duplicate=nums[i];
            }
            sum+=nums[i];
        }
        sum+=nums[0];
        ans.push_back(duplicate);
        int sumWoDup=sum-duplicate;
        int missing=totSum-sumWoDup;
        ans.push_back(missing);
        return ans;
        

    }
};