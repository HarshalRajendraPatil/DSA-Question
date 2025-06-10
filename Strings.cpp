// Q1. Given a string s , return reverse of the string as output.

class Solution {
  public:
    string revStr(string s) {
        string res = s;
        int i = 0;
        int j = res.size() - 1;
        while(i <= j){
            swap(res[i], res[j]);
            i++;
            j--;
        }
        return res;
    }
};

// Q2. Given a string S. Count the characters that have ‘N’ number of occurrences. If a character appears consecutively it is counted as 1 occurrence.

class Solution {
  public:
    int getCount(string S, int N) {
        unordered_map<char, int> freq;
        char prev = '\0';
    
        for (char ch : S) {
            if (ch != prev) {
                freq[ch]++;
                prev = ch;
            }
        }
    
        int count = 0;
        for (auto& entry : freq) {
            if (entry.second == N) {
                count++;
            }
        }
    
        return count;
    }
};

// Q3. Given a string s. The task is to convert string characters to lowercase.

class Solution {
  public:
    string toLower(string& s) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] < 97) s[i] = char(s[i] + 32);
        }
        return s;
    }
};


// Q4. Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        unordered_map<char,int>mpp;
        set<char>se;
        for(char c:s){
            mpp[c]++;
        }
        for(auto it: mpp){
            if(it.second == 1) se.insert(it.first);
        }
        for(char c:s){
            if(se.count(c)) return c;
        }
        return '$';
    }
};


// Q5. Given a string s which may contain lowercase and uppercase characters. The task is to remove all duplicate characters from the string and find the resultant string. The order of remaining characters in the output should be same as in the original string.

class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        string res = "";
        vector<int> vect(256, 0);
        for(char c:s){
            vect[c - '0'] = 1;
        }
        for(char c : s){
            if(vect[c - '0'] == 1){
                res+=c;
                vect[c - '0'] = 0;
            }
        }
        return res;
    }
};


// Q6. You are given a string s , the task is to reverse the string using stack.

class Solution {
  public:
    string reverse(const string& s) {
        stack<char> st;
        string res = "";
        for(auto c : s){
            st.push(c);
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};


// Q7. You are given a string s, consisting of lowercase alphabets. Your task is to remove consecutive duplicate characters from the string. 

class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        string res = "";
        for(int i = 0; i <= s.size() - 1; i++){
            if(s[i] != s[i + 1]) res += s[i];
        }
        return res;
    }
};
