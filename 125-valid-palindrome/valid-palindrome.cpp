class Solution {
public:
    bool check(string &s, int i, int j){
        if(s.size()==1) return true;
        while(i<j){
            while(i<j && !isalnum(s[i])){
                i++;
            }
            while(i<j && !isalnum(s[j])){
                j--;
            }
            if(tolower(s[i])==tolower(s[j])){
                i++, j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        int n=s.size();
        return check(s, 0, n-1);
    }
};