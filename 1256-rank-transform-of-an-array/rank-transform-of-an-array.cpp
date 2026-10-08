class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> nums;
        nums=arr;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int rank=1;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=rank;
                rank++;
            }
        }
        vector<int> ans(arr.size());
        for(int i=0; i<arr.size(); i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};