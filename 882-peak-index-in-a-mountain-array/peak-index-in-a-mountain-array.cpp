class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int ind=-1;
        int ans=-1;
        for(int i=0; i<n; i++){
            if(arr[i]>ans){
                ans=max(ans, arr[i]);
                ind=i;
            }
            
        }
        return ind;
    }
};