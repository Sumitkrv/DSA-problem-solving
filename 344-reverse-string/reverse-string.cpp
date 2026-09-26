class Solution {
public:
    void f(vector<char>& s, vector<char> &charArr, int n, int i){
        if(i==n) return;
        f(s, charArr, n, i+1);
        charArr.push_back(s[i]);
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        vector<char> charArr;
        f(s, charArr, n, 0);
        s=charArr;
    }
};