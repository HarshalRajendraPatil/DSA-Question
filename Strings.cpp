// Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res = "";
        for(char c: s){
            if (st.empty()){
                st.push(c);
            }else if (c == '('){
                res+='(';
                st.push(c);
            }else{
                char top = st.top();
                st.pop();
                if (!st.empty()) res+=c;
            }

        }
        return res;
    }
};
