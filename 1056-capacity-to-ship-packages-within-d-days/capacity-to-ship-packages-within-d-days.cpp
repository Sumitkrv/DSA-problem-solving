class Solution {
public:
    int func(vector<int>& weights, int mid){
        int n=weights.size();
        int days=1, load=0;
        for(int i=0; i<n; i++){
            if(weights[i]+ load>mid){
                days+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;


    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(), weights.end());
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=weights[i];
        }
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int noOfDays=func(weights, mid);
            if(noOfDays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};