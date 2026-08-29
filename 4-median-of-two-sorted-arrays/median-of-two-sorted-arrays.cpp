class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int h=(m+n);
        int ind1=h/2-1;
        int ind2=h/2;
        int ind1el=-1;
        int ind2el=-1;
        int i=0, j=0, cnt=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1) ind1el=nums1[i];
                if(cnt==ind2) ind2el=nums1[i];
                cnt++, i++;

            }
            else{
                if(cnt==ind1) ind1el=nums2[j];
                if(cnt==ind2) ind2el=nums2[j];
                cnt++, j++;
            }
        }
        while(i<n){
            if(cnt==ind1) ind1el=nums1[i];
            if(cnt==ind2) ind2el=nums1[i];
            i++, cnt++;
        }
        while(j<m){
            if(cnt==ind1) ind1el=nums2[j];
            if(cnt==ind2) ind2el=nums2[j];
            j++, cnt++;
        }
        if(h%2==1){
            return ind2el;
        }
        return (double)((double)(ind1el+ind2el))/2.0;

    }
};