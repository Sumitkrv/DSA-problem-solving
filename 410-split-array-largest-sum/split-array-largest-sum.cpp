class Solution {
public:
    int f(vector<int>& nums, int mid){
        int cntSub=1, sum=0;
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                cntSub++;
                sum=nums[i];
            }
        }
        return cntSub;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(), nums.end());
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int count=f(nums, mid);
            if(count>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};