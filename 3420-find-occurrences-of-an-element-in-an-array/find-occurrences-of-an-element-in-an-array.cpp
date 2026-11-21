class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n=nums.size();
        vector<int> ans;
        vector<int> index;
        for(int i=0; i<n; i++){
            if(nums[i]==x){
                index.push_back(i);
            }
        }
        for(int j=0; j<queries.size(); j++){
            int k=queries[j];
            if(k>index.size()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(index[k-1]);
            }
        }
        return ans;
    }
};