// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int>mpp;
        for(char c : s)mpp[c]++;
        for(char c : t){
            if(mpp.find(c) == mpp.end()) return false;
            if(mpp[c] == 0) return false;
            mpp[c]--;
        }
        for(auto [c,i] : mpp){
            if (i != 0) return false;
        }
        return true;
    }
};


// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int idx = n-1;
        string res = "";
        while(idx >= 0){
            int digit = num[idx] - '0';
            if (digit % 2 != 0) break;
            idx--;
        }
        for(int i = 0; i <= idx; i++){
            res += num[i];
        }
        return res;
    }
};


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
