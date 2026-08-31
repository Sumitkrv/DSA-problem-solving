class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         int n=nums.size();
         stack<pair<int,int>> st;
         vector<int> ans(n, -1);
        for(int i=0; i<2*n; i++){
            int index=i%n;
            while(!st.empty() && nums[index]>st.top().first){
                int idx=st.top().second;
                st.pop();
                ans[idx]=nums[index];
            }
            if(i<n){
            st.push({nums[index], index});
            }
        }
        return ans;
    }
};