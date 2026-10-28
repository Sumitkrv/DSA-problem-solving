class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int first=nums[i];
            if(mp.find(first)!=mp.end()){
                return true;
            }
            mp[nums[i]]++;
        }
        return false;
    }
};