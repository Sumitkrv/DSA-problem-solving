class Solution {
public:
    // int f(int n, vector<int> &dp){
    //     if(n<=1){
    //         return n;
    //     }
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=f(n-1, dp)+f(n-2, dp);
    // }
    int fib(int n) {
        if(n<=1) return n;
        //vector<int> dp(n+1, 0);
        int prev1=1, prev2=0;
        
        for(int i=2; i<=n; i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
};