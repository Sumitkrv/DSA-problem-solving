class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        vector<int> even;
        vector<int> odd;
        for(char ch: s){
            int x=ch-'0';
            if(x%2==0){
                even.push_back(x);
            }
            else{
                odd.push_back(x);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        string ans="";
        for(char ch: s){
            int x=ch-'0';
            if(x%2==0){
                ans+=char(even.back()+'0');
                even.pop_back();
            }
            else{
                ans+=char(odd.back()+'0');
                odd.pop_back();
            }
        }
        return stoi(ans);
    }
};