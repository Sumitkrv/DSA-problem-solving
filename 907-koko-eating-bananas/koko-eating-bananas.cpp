class Solution {
public:
    int findMax(vector<int>& piles, int n){
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            maxi=max(piles[i], maxi);
        }
        return maxi;
    }
    int findHour(vector<int> &piles, int k){
        int n=piles.size();
        int hour=0;
        for(int i=0; i<n; i++){
            hour+=ceil((double) piles[i]/(double) k);
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1; 
        int high=findMax(piles, n);
        while(low<=high){
            int mid=high-(high-low)/2;
            int hourly=findHour(piles, mid);
            if(hourly<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};