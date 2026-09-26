class Solution {
public:
    bool f(int n){
        if(n==1) return true;
        if(n%3==0){
            return f(n/3);
        }
        return false;
    }
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(f(n)) return true;
        return false;
    }
};