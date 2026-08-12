class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        stack<int> st;
        string ans="";
        for(int i=0; i<=n; i++){
            st.push(i+1);
            if(i==n || pattern[i]=='I'){
                while(!st.empty()){
                    ans+=char(st.top()+'0');
                    st.pop();
                }
            }
        }
        return ans;
    }
};