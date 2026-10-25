class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0, j=n-1;
        int maxWater=INT_MIN;
        while(i<j){
            maxWater=max(maxWater, (j-i)*min(height[i], height[j]));
            if(height[i]<height[j]){
                i++;
            }
            else {
                //maxWater=max(maxWater, (j-i+1)*min(height[i], height[j]));
                j--;
            }
        }
        return maxWater;
    }
};