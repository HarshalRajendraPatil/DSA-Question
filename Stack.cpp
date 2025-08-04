// Q1. Given an integer array arr. For each element in the array, check whether the right adjacent element (on the next immediate position) of the array is smaller. If the next element is smaller, update the current index to that element. If not, then update to -1.

class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        stack<pair<int, int>> st;
        for(int i = arr.size() - 1; i >= 0; i--){
            if(i == arr.size() - 1){
                st.push({arr[i], -1});
            }else{
                if(arr[i] > st.top().first){
                    st.push({arr[i], st.top().first});
                }else{
                    st.push({arr[i], -1});
                }
            }
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = st.top().second;
            st.pop();
        }
    }
};


// Q2. You are given an array arr[], the task is to reverse the array elements in-place by using a stack.

class Solution {
  public:
    void reverseArray(vector<int>& arr) {
        stack<int> st;
        for(int i : arr){
            st.push(i);
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = st.top();
            st.pop();
        }
    }
};


// Q3. Given a stack of integers and Q queries. The task is to perform the operation on stack according to the query.

void insert(stack<int> &s, int x) {
    s.push(x);
}

void remove(stack<int> &s) {
    s.pop();
}

void headOf_Stack(stack<int> &s) {
    int x = s.top();
    cout << x << " " << endl;
}

bool find(stack<int> s, int val) {
    bool exists = false;
    
    stack<int> tempS = s;
    
    while(!tempS.empty()){
        if(tempS.top() == val){
            exists = true;
            break;
        }
        tempS.pop();
    }

    if (exists == true) {
        return true;
    } else {
        return false;
    }
}


// Q4. You are given an integer array arr[]. You need to push the elements of the array into a stack and then print them while popping.

class Solution {
  public:
    // Function to push elements of an array into a stack.
    stack<int> push(vector<int> &arr) {
        int n = arr.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            s.push(arr[i]);
        }
        return s;
    }

    // Function to pop elements from a stack and print them.
    void pop(stack<int> s) {
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
};


// Q5. Given a stack of integers of size N, your task is to complete the function pairWiseConsecutive(), that checks whether numbers in the stack are pairwise consecutive or not. The pairs can be increasing or decreasing, and if the stack has an odd number of elements, the element at the top is left out of a pair. 

bool pairWiseConsecutive(stack<int> s) {
    while(!s.empty()){
        int a = s.top(), b;
        s.pop();
        if(s.size() > 0){
            b = s.top();
            s.pop();
            if ((a - b) > 1 || (a - b) < -1){
                return 0;
            }
        }
    }
    
    
    return 1;
}


// Q6. Given an array of negative and non-negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers, arr[i] and arr[i+1] are either negative or non-negative. And you can do the following operation any number of times until the array becomes beautiful.

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> s;
        for(int i = 0; i < arr.size(); i++) {
            
            
            
            if(!s.empty() && ((s.top() >= 0 && arr[i] < 0) || (s.top() < 0 && arr[i] >= 0))) {
                // Opposite signs → cancel out
                s.pop();
            } else {
                s.push(arr[i]);
            }
        }

        // Now move from stack to vector in correct order
        vector<int> vec(s.size());
        for(int i = s.size() - 1; i >= 0; i--) {
            vec[i] = s.top();
            s.pop();
        }

        return vec;
    }
};


// Q7. Given an array arr[] and a number k. The task is to delete k elements that are smaller than the next element (i.e., we delete arr[i] if arr[i] < arr[i+1]) or become smaller than the next because the next element is deleted.

class Solution {
  public:
    vector<int> deleteElement(vector<int>& arr, int k) {
        stack<int> s;
        for (int i : arr) {
            while (!s.empty() && k > 0 && s.top() < i) {
                s.pop();
                k--;
            }
            s.push(i);
        }

        // Get stack contents in reverse order
        vector<int> res(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }

        return res;
    }
};


// Q8. Tom is a string freak. He has got sequences of words arr[] to manipulate. If in a sequence, two same words come together then Tom destroys each other. Find the number of words left in the sequence after this pairwise destruction. 

class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        stack<string> s;
        for(string i : arr){
            if(!s.empty() && s.top() == i){
                while(!s.empty() && s.top() == i){
                    s.pop();
                }
            }else{
                s.push(i);
            }
        }
        return s.size();
    }
};


// Q9. Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        vector<int> res;
        stack<pair<char, int>>s;
        int num = 1;
        for(char c : str){
            if(c == '(' || c == ')'){
                if(!s.empty()){
                  if(s.top().first == '(' && c == ')'){
                      s.push({c, s.top().second});
                      res.push_back(s.top().second);
                      s.pop();
                      s.pop();
                  }else{
                      s.push({c, num});
                      res.push_back(num);
                      num++;
                  }
                }else{
                  s.push({c, num});
                  res.push_back(num);
                  num++;
                }
            }
        }
        return res;
    }
};


// Q10. You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack. 

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        stack<int> s;
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        s.push(x);
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        return st;
    }
};


// Q11. Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int>right(n, -1);
        vector<int>left(n, -1);
        
        // starting for next greater
        int greater = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if(heights[i] < heights[greater]){
                right[i] = greater;
            }else{
                greater = i;
            }
        }

        // starting for previous greater
        greater = 0;
        for(int i = 0; i < n; i++){
            if(heights[i] < heights[greater]){
                left[i] = greater;
            }else{
                greater = i;
            }
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            if(left[i] == -1 || right[i] == -1){
                continue;
            }else{
                sum = sum + min(heights[right[i]], heights[left[i]]) - heights[i];
            }
        }
        return sum;
    }
};


// Q12. Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n, 0);
        vector<int> left(n, -1);
        stack<int>st;

        for(int i = n - 1; i >= 0; i--){
            while(st.size()>0 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();       
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = 0; i < n; i++){
            while(st.size() > 0 && heights[i] <= heights[st.top()]){
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();       
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }
        return ans;
    }
};


// Q13. Given a balanced parentheses string s, return the score of the string.

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int>st;
        for(char c:s){
            if(c == '('){
                st.push(score);
                score = 0;
            }else{
                score = st.top() + max(2*score, 1);
                st.pop();
            }
        }
        return score;
    }
};


// Q14. Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>right(n, -1);
        vector<int>left(n, -1);
        vector<int>res(n, -1);
        stack<int>st;

        // starting for next greater
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            right[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // starting for previous greater
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] > nums[i]){
                    left[i] = j;
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(left[i] == -1 && right[i] == -1){
                res[i] = -1;
                continue;
            }else{
                if(right[i] != -1){
                    res[i] = nums[right[i]];
                }else{
                    res[i] = nums[left[i]];
                }
            }
        }
        return res;
    }
};

// Q15. Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string st; // acts like a stack

        for(int i = 0; i < n; i++){
            while(!st.empty() && k > 0 && st.back() > num[i]){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }

        // Remove remaining k digits from the end
        while(k > 0 && !st.empty()){
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int start = 0;
        while(start < st.size() && st[start] == '0') {
            start++;
        }

        string result = st.substr(start);
        return result.empty() ? "0" : result;
    }
};


// Q16. You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

class Node {
    public:
    string data;
    Node* next;
    Node* prev;

    Node(string val){
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
public:
    Node* head = NULL;
    int size = 0;
    Node* trav = head;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        trav = head;
    }
    
    void visit(string url) {
        head = trav;
        Node* newNode = new Node(url);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
        trav = head;
    }
    
    string back(int steps) {
        while(trav->next != NULL && steps > 0){
            steps--;
            trav = trav->next;
        }
        return trav->data;
    }
    
    string forward(int steps) {
        while(trav->prev != NULL && steps > 0){
            steps--;
            trav = trav->prev;
        }
        return trav->data;
    }
};


// Q17. Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        for(int ele:pushed){
            st.push(ele);
            while(!st.empty() && popped.size()>0 && st.top() == popped[0]){
                st.pop();
                popped.erase(popped.begin());
            }
        }
        return st.empty();        
    }
};


// Q18. Given a string s of '(' , ')' and lowercase English characters. Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> toRemove;

        // First pass to find unmatched parentheses
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    toRemove.insert(i);
                }
            }
        }

        // Add remaining unmatched '(' indices to removal set
        while (!st.empty()) {
            toRemove.insert(st.top());
            st.pop();
        }

        // Build the result string
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (toRemove.find(i) == toRemove.end()) {
                res += s[i];
            }
        }

        return res;
    }
};


// Q19. Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

class Solution {
public:
    int largestRectangle(vector<int>& heights){
        int n = heights.size();
        vector<int> right(n, n);
        vector<int> left(n, -1);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(st.size() > 0 && heights[i] <= heights[st.top()]){
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = 0; i < n; i++){
            while(st.size() > 0 && heights[i] <= heights[st.top()]){
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int curArea = heights[i] * width;
            maxArea = max(maxArea, curArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pSum(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += (matrix[i][j] - '0');
                if(matrix[i][j] == '0') sum = 0;
                pSum[i][j] = sum;
            }
        }
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int curArea = largestRectangle(pSum[i]);
            maxArea = max(maxArea, curArea);
        }
        return maxArea;
    }
};


Q20. You are given the head of a singly linked-list. The list can be represented as: L0 → L1 → … → Ln - 1 → Ln. Reorder the list to be on the following form: L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …. You may not modify the values in the list's nodes. Only nodes themselves may be changed.

class Solution {
public:
    void reorderList(ListNode* head) {
        int size = 0;
        stack<ListNode*> st;
        ListNode* ptr1 = head;
        ListNode* ptr2 = NULL;
        while(ptr1 != NULL){
            st.push(ptr1);
            ptr1 = ptr1->next;
            size++;
        }
        if(size == 0 || size == 1 || size == 2) return;
        ptr1 = head;
        ptr2 = st.top();
        st.pop();
        while(!st.empty() && ptr1 != ptr2 && ptr1->next != ptr2){
            ListNode* temp = ptr1->next;
            ptr1->next = ptr2;
            ptr2->next = temp;
            ptr2 = st.top();
            st.pop();
            ptr1 = temp;
        }
        if(ptr1->next == ptr2){
            ptr1->next = ptr2;
        }
            ptr2->next = NULL;
    }
};
