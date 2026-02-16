// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

class Solution {
public:
    int myAtoi(string s) {
        int startIdx = 0;
        int n = s.size();
        int sign = 1; 

        while(startIdx < n && s[startIdx] == ' ') startIdx++;
        if (startIdx == n) return 0;
        if (s[startIdx] == '-'){
            sign = -1;
            startIdx++;
        } else if (s[startIdx] == '+') {
            startIdx++;
        }

        long num = 0; 

        while(startIdx < n){
            if (s[startIdx] < '0' || s[startIdx] > '9') {
                break;
            }

            int digit = s[startIdx] - '0';
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            startIdx++;
        }

        return (int)(num * sign);
    }
};


// You are given a stack of integers. Your task is to reverse the stack using recursion. You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop constructs or additional data structures like arrays or queues.

class Solution {
public:
    void insertAtBottom(stack<int>& st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }
        int num = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(num);
    }

    void reverseStack(stack<int> &st) {
        if (st.empty()) {
            return;
        }
        int num = st.top();
        st.pop();
        Reverse(st);
        insertAtBottom(st, num);
    }
};
