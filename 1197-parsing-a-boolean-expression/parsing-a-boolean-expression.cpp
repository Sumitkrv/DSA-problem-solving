class Solution {
public:
    bool find(list<char> &ls, char val){
        for(char ch: ls){
            if(ch==val) return true;
        }
        return false;
    }
    char evaluate(list<char> &ls, char op){
        if(op=='&'){
            if(find(ls, 'f')){
                return 'f';
            }
            else return 't';
        }
        else if(op=='|'){
            if(find(ls, 't')){
                return 't';
            }
            else return 'f';
        }
        else{ // not operator
            if(ls.front()=='t'){
                return 'f';
            }
            else return 't';
        }
    }
    bool parseBoolExpr(string expression) {
        int n=expression.size();
        stack<char> st;
        for(char ch: expression){
            if(ch==')'){
                list<char> ls;
                while(st.top()!='('){
                    ls.push_back(st.top());
                    st.pop();
                }
                st.pop(); //remove the opening bracket
                char op=st.top();
                st.pop();
                char ans=evaluate(ls, op);
                st.push(ans);
            }
            else{
                if(ch!=','){
                    st.push(ch);
                }
            }
        }
        return st.top()=='t';
    }
};