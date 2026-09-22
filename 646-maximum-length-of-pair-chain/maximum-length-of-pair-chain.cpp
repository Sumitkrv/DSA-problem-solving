class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if(n==0) return 0;
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b){
            return a[1]<b[1];   // sorting according to the end
        });
        int cnt=0;
        int i=0, j=i+1;
        while(j<n){
            if(pairs[i][1]<pairs[j][0]){
                cnt++;
                i=j;
            }
            j++;

        }
        return cnt+1;
    }
};