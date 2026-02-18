// Return a string of the words in reverse order concatenated by a single space.

class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string temp = "";
        for(char c: s){
            if (c == ' '){
                if (temp != "") st.push(temp);
                temp = "";
                continue;
            }
            temp += c;
        }
        if (temp != ""){
            st.push(temp);
            temp = "";
        }
        while(!st.empty()){
            string res = st.top();
            st.pop();
            if (!st.empty()){
                temp = temp + res + " ";
            }else {
                temp = temp + res;
            }
        }
        return temp;
    }
};


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
