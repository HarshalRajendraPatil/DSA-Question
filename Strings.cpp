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
