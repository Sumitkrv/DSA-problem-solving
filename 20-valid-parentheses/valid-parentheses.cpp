class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        //if(n==1) return false;
        //if(s[0]==')' || s[0]==']' || s[0]=='}') return false;
        stack<int> st;
        for(char ch: s){
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                if(st.top()=='(' && ch==')'){
                    st.pop();
                }
                else if(st.top()=='[' && ch==']'){
                    st.pop();
                }
                else if(st.top()=='{' && ch=='}'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;

    }
};