class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        long long  common=min(need1, need2);
        long long remain1=need1-common;
        long long remain2=need2-common;
        ans+=common*min(costBoth, cost1+cost2);
        ans+=remain1*min(costBoth, cost1);
        ans+=remain2*min(costBoth, cost2);
        return ans;
    }
};