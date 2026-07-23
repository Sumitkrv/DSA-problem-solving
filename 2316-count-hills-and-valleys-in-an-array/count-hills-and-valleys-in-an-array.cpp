class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        vector<int> compressed;
        compressed.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i]!=compressed.back()){
                compressed.push_back(nums[i]);
            }
        }
        int m=compressed.size();
        int cnt=0;
        for(int i=1; i<m-1; i++){
            if(compressed[i]>compressed[i-1] && compressed[i]>compressed[i+1]){
                cnt++;
            }
            else if(compressed[i]<compressed[i-1] && compressed[i]<compressed[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};