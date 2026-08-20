class Solution {
public:
    int firstOccurance(vector<int> &nums, int n, int target){
        int low=0; int high=n-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return first;
    }
    int secondOccurance(vector<int>& nums, int n, int target){
        int low=0; int high=n-1;
        int second=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                second=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return second;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=firstOccurance(nums, n, target);
        if(first==-1) return {-1, -1};
        int second=secondOccurance(nums, n, target);
        return {first, second};
    }
};