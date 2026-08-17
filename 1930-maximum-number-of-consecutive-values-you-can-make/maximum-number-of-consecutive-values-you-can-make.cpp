class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n=coins.size();
        sort(coins.begin(), coins.end());
        int range=0;
        for(int coin: coins){
            if(coin>range+1){
                break;
            }
            range+=coin;
        }
        return range+1;
    }
};