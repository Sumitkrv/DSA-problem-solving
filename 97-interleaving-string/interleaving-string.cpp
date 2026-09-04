class Solution {
public:
    bool f(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
        bool takeS1=false;
        bool takeS2=false;
        if(i>=0 && s1[i]==s3[i+j+1]){
            takeS1=f(i-1, j, s1, s2, s3, dp);
        }
        if(j>=0 && s2[j]==s3[i+j+1]){
            takeS2=f(i, j-1, s1, s2, s3, dp);
        }
        return dp[i+1][j+1]= takeS1 || takeS2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m!=s3.size()){
            return false;
        }
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n-1, m-1, s1, s2, s3, dp);
    }
};