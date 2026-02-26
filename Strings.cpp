// Given a roman numeral, convert it to an integer.

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int number = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // Check if current value is smaller than the next value
            if (i < n - 1 && mpp[s[i]] < mpp[s[i+1]]) {
                number -= mpp[s[i]];
            } else {
                number += mpp[s[i]];
            }
        }
        return number;
    }
};


// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string. Return the sorted string. If there are multiple answers, return any of them.

class Solution {
public:
    typedef pair<char, int> P;
    string frequencySort(string s) {
        vector<P> vec(123);
        for(char c: s){
            int freq = vec[c].second;
            vec[c] = {c, freq + 1};
        }
        auto lambda = [&](P&p1, P&p2){
            return p2.second < p1.second;
        };

        sort(vec.begin(), vec.end(), lambda);
        string res = "";

        for(int i = 0; i < 123; i++){
            if (vec[i].second > 0){
                char c = vec[i].first;
                int freq = vec[i].second;
                string temp = string(freq, c);
                res+=temp;
            }
        }
        return res;
    }
};


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
