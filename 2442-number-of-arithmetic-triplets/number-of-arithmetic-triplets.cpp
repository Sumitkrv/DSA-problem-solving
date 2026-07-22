class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size();
        int cnt=0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(int x: nums){
            if(st.count(x+diff) && st.count(x+2*diff)){
                cnt++;
            }
        }
       return cnt;
    }
};