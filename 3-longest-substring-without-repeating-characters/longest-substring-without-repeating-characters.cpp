class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxLen=0;
        int hash[256];
        fill(hash, hash+256, -1);
        int l=0, r=0;
        //int len=0;
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxLen=max(maxLen, len);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};