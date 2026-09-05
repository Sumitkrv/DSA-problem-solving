class Solution {
public:
    bool f(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        if(i==s1.size() && j==s2.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool takeS1=false;
        bool takeS2=false;
        if(i<s1.size() && s1[i]==s3[i+j]){
            takeS1=f(i+1, j, s1, s2, s3, dp);
        }
        if(j<s2.size() && s2[j]==s3[i+j]){
            takeS2=f(i, j+1, s1, s2, s3, dp);
        }
        return dp[i][j]= takeS1 || takeS2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m!=s3.size()){
            return false;
        }
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(0, 0, s1, s2, s3, dp);
    }
};