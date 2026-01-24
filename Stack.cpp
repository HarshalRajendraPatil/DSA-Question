// LFU Cache

struct Node {
    int key, val, freq;
    Node *next, *prev;
    Node(int k, int v)
        : key(k), val(v), freq(1), next(nullptr), prev(nullptr) {}
};

struct List {
    Node *head, *tail;
    int size;
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* node) {
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;
    int maxSize;
    int curSize;
    int minFreq;

public:
    LFUCache(int capacity) {
        maxSize = capacity;
        curSize = 0;
        minFreq = 0;
    }

    void updateFreqList(Node* node) {
        freqList[node->freq]->removeNode(node);

        if (node->freq == minFreq && freqList[node->freq]->size == 0) {
            minFreq++;
        }

        node->freq++;
        if (freqList.find(node->freq) == freqList.end()) {
            freqList[node->freq] = new List();
        }
        freqList[node->freq]->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];
        updateFreqList(node);
        return node->val;
    }

    void put(int key, int value) {
        if (maxSize == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreqList(node);
            return;
        }

        if (curSize == maxSize) {
            List* minFreqList = freqList[minFreq];
            Node* nodeToEvict = minFreqList->tail->prev;

            keyNode.erase(nodeToEvict->key);
            minFreqList->removeNode(nodeToEvict);
            curSize--;
            delete nodeToEvict;
        }

        curSize++;
        minFreq = 1;

        Node* newNode = new Node(key, value);
        keyNode[key] = newNode;

        if (freqList.find(minFreq) == freqList.end()) {
            freqList[minFreq] = new List();
        }
        freqList[minFreq]->addFront(newNode);
    }
};


// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

class StockSpanner {
public:
    stack<pair<int, int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while(!st.empty() && st.top().first <= price){
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};


// Prefix to Infix Conversion

class Solution {
public:
    string prefixToInfix(string s) {
        reverse(s.begin(), s.end());
        stack<string>st;
        for(char c: s){
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                st.push(string{c});
            }else {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                string ans = "(" + a + c + b + ")";
                st.push(ans);
            }
        }
        return st.top();
    }
};


// Postfix to Infix Conversion

class Solution {
public:
    string postToInfix(string postExp) {
        string res;
        stack<string> st;
        for(char c: postExp){
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                st.push(string{c});
            }else {
                string b = st.top();
                st.pop();
                string a = st.top();
                st.pop();
                string ans = "(" + a + c + b + ")";
                st.push(ans);
            }
        }
        res = st.top();
        st.pop();
        return res;
    }
};


// Infix to Prefix Conversion

class Solution {
public:
    int prece(char c){
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return 0;
    }
    string infixToPrefix(const string& s) {
        string str;
        reverse(str.begin(), str.end());
        string res;
        stack<char>st;
        for (char c: str){
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                res += c;
            }else if (c == ')'){
                st.push(c);
            }
            else if (c == '('){
                while(!st.empty() && st.top() != ')'){
                    res+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }else {
                if (st.empty()){
                    st.push(c);
                }else {
                    while(!st.empty() && prece(c) <= prece(st.top())){
                        res+=st.top();
                        st.pop();
                    }
                    st.push(c);
                }
            }
        }

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray. Return the sum of all subarray ranges of nums.
class Solution {
public:
    vector<int> nge(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> pgee(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> nse(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> psee(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        vector<int> ngeVec = nge(nums);
        vector<int> pgeeVec = pgee(nums);
        vector<int> nseVec = nse(nums);
        vector<int> pseeVec = psee(nums);
        long long sum = 0;
    
        for(int i = 0; i < nums.size(); i++){
            long long leftSmall = i - pseeVec[i];
            long long rightSmall = nseVec[i] - i;
            long long leftBig = i - pgeeVec[i];
            long long rightBig = ngeVec[i] - i;
            
            sum = sum + ((leftBig * rightBig) - (leftSmall * rightSmall)) * nums[i];
        }
        return sum;
    }
};


// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array. You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2. For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1. Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mpp;
        stack<int>st;
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            if (st.empty()){
                mpp[nums2[i]] = -1;
            }else {
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> res;
        for(int num : nums1){
            res.push_back(mpp[num]);
        }
        return res;
    }
};


// You are given a valid prefix expression consisting of binary operators and single-character operands. Your task is to convert it into a valid postfix expression.

class Solution {
public:
    string prefixToPostfix(const string& s) {
        string str = s;
        reverse(str.begin(), str.end());
        stack<string>st;
        for(char c : str){
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                st.push(string{c});
            }else {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                string ans = a + b + c;
                st.push(ans);
            }
        }
        return st.top();
    }
};


// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c : s){
            if (c == '(' || c == '{' || c == '['){
                st.push(c);
            }else {
                if (st.empty()){
                    return false;
                }else {
                    if (c == ')' && st.top() == '(' || c == '}' && st.top() == '{' || c == ']' && st.top() == '['){
                    st.pop();
                }else {
                    st.push(c);
                }
                }
            }
        }
        return st.empty();
    }
};


// Given an integer array arr. For each element in the array, check whether the right adjacent element (on the next immediate position) of the array is smaller. If the next element is smaller, update the current index to that element. If not, then update to -1.

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


// You are given an array arr[], the task is to reverse the array elements in-place by using a stack.

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


// Given a stack of integers and Q queries. The task is to perform the operation on stack according to the query.

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


// You are given an integer array arr[]. You need to push the elements of the array into a stack and then print them while popping.

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


// Given a stack of integers of size N, your task is to complete the function pairWiseConsecutive(), that checks whether numbers in the stack are pairwise consecutive or not. The pairs can be increasing or decreasing, and if the stack has an odd number of elements, the element at the top is left out of a pair. 

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


// Given an array of negative and non-negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers, arr[i] and arr[i+1] are either negative or non-negative. And you can do the following operation any number of times until the array becomes beautiful.

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


// Given an array arr[] and a number k. The task is to delete k elements that are smaller than the next element (i.e., we delete arr[i] if arr[i] < arr[i+1]) or become smaller than the next because the next element is deleted.

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


// Tom is a string freak. He has got sequences of words arr[] to manipulate. If in a sequence, two same words come together then Tom destroys each other. Find the number of words left in the sequence after this pairwise destruction. 

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


// Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

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


// You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack. 

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


// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

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


// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

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


// Given a balanced parentheses string s, return the score of the string.

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


// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

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

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

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


// You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

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


// Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

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


// Given a string s of '(' , ')' and lowercase English characters. Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

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


// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

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


// You are given the head of a singly linked-list. The list can be represented as: L0 → L1 → … → Ln - 1 → Ln. Reorder the list to be on the following form: L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …. You may not modify the values in the list's nodes. Only nodes themselves may be changed.

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


// Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

class Node {
public:
    int data;
    int freq;
    Node* next;
    Node* prev;
    Node(int val){
        this->data = val;
        this->freq = 1;
        this->next = NULL;
        this->prev = NULL;
    }
};

class FreqStack {
public:
    Node* head;
    unordered_map<int, int> mpp;

    FreqStack() {
        head = NULL;
    }

    void push(int val) {
        mpp[val]++;
        Node* newNode = new Node(val);
        newNode->freq = mpp[val];
        if (head) {
            head->next = newNode;
            newNode->prev = head;
            head = newNode;
        } else {
            head = newNode;
        }
    }

    int pop() {
        int maxFreq = 0;
        for (auto it : mpp) {
            maxFreq = max(maxFreq, it.second);
        }

        Node* trav = head;
        int data = 0;
        while (trav) {
            if (trav->freq == maxFreq) {
                data = trav->data;
                Node* p = trav->prev;
                Node* n = trav->next;

                if (p) {
                    p->next = n;
                }
                if (n) {
                    n->prev = p;
                }

                if (trav == head) {
                    head = p;
                }

                delete trav;
                mpp[data]--;
                break;
            }
            trav = trav->prev;
        }
        return data;
    }
};


// Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

class StackUsingQueues {
private:
    queue<int> q1, q2;
    
public:
    void push(int data) {
        // Add to q2
        q2.push(data);
        
        // Transfer all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2
        swap(q1, q2);
    }
    
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return INT_MIN;
        }
        
        int data = q1.front();
        q1.pop();
        return data;
    }
    
    int top() {
        if (q1.empty()) {
            return INT_MIN;
        }
        return q1.front();
    }
    
    bool isEmpty() {
        return q1.empty();
    }
};
