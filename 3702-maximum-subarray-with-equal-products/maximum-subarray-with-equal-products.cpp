class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int l=1;
            int g=0;
            int prod=1;
            for(int j=i; j<n; j++){
                prod*=nums[j];
                l=lcm(nums[j], l);
                g=gcd(nums[j], g);
                if(prod==g*l){
                    ans=max(ans, j-i+1);
                }
                if(prod>25200){
                    break;
                }
            }
        }
        return ans;
    }
};