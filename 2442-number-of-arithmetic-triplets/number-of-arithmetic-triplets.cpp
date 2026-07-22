class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size();
        int cnt=0;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        for(int i=0; i<n; i++){
            if(st.find(nums[i]+ diff)!=st.end() && st.find(nums[i]+ 2*diff)!=st.end()){
                cnt++;
            }
        }
       return cnt;
    }
};