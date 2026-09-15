class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(), tokens.end());
        int i=0, j=n-1;
        int score=0;
        int ans=0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
                ans=max(ans, score);
            }
            else if(tokens[j]>power && score>0){
                score--;
                power+=tokens[j];
                j--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};