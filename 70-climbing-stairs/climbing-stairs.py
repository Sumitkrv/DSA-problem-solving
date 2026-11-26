class Solution:
    def f(self, ind: int, dp: list[int])->int:
        if ind==0:
            return 1
        if ind==1:
            return 1
        if dp[ind]!=-1:
            return dp[ind]
        
        oneStep=self.f(ind-1, dp)
        twoStep=self.f(ind-2, dp)
        dp[ind]=oneStep+twoStep
        return dp[ind]
    def climbStairs(self, n: int) -> int:
        dp=[-1]*(n+1)
        return self.f(n, dp)