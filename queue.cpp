// Q1. Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() { 
        if(empty()) return -1;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int data = s2.top();
        s2.pop();
        return data;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
            return s2.empty() && s1.empty();
    }
};


// Q2. Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;
        queue<char> q;
        for(char c: s){
            mpp[c]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(mpp[s[i]] == 1) return i;
        }
        return -1;
    }
};


// Q3. Given a number n. The task is to generate all binary numbers with decimal values from 1 to n.

vector<string> generate(int n) {
    vector<string>v;
    queue<string> q;
    q.push("1");
    for(int i = 0; i < n; i++){
        string curr = q.front();
        q.pop();
        v.push_back(curr);
        q.push(curr + "0");
        q.push(curr + "1");
    }
    return v;   
}


// Q4. You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements outside the window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Add current element
            dq.push_back(i);
            
            // Add maximum to result if window is complete
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};


// Q5. Given a queue q containing integer elements, your task is to reverse the queue.

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> s;
    
        // Transfer all elements to stack
        while (!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        
        // Transfer back to queue (this reverses the order)
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        return q;
    }
};


// Q6. You are given an m x n grid where each cell can have one of three values: 0 representing an empty cell, 1 representing a fresh orange, or 2 representing a rotten orange. Every minute, any fresh orange that is 4D adjacent to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    
    if (fresh == 0) return 0;
    
    int time = 0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty() && fresh > 0) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int j = 0; j < 4; j++) {
                int newRow = row + directions[j][0];
                int newCol = col + directions[j][1];
                
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 
                    grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2;
                    q.push({newRow, newCol});
                    fresh--;
                }
            }
        }
        
        if (!q.empty()) time++;
    }
    
    return fresh == 0 ? time : -1;
}
};


// Q7. Implement a Queue using an Array.

void MyQueue::push(int x) {
    if (rear >= 100005) return; // Optional: overflow check
    arr[rear++] = x;
}

// Function to pop an element from queue and return that element.
int MyQueue::pop() {
    if (front == rear) {
        return -1; // Queue is empty
    }

    int data = arr[front++];
    
    // Optional: Reset indices if queue becomes empty
    if (front == rear) {
        front = 0;
        rear = 0;
    }

    return data;
}


// Q8. Implement a Queue using Linked List. 

void MyQueue::push(int x) {
    QueueNode* node = new QueueNode(x);
    if (rear == NULL) {
        rear = front = node;
        return;
    }
    rear->next = node;
    rear = node;
}

int MyQueue::pop() {
    if (front == NULL)
        return -1;

    int data = front->data;
    QueueNode* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
    return data;
}


// Q9. You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;

        for(int i = 0; i < nums.size(); i++){
            while(!q.empty() && q.front() <= i - k){
                q.pop_front();
            }

            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }

            q.push_back(i);

            if(i >= k - 1){
                res.push_back(nums[q.front()]);
            }
        }

        return res;
    }
};


// Q10. Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> res;
        queue<int> q;
        
        for(int i = 0; i < arr.size(); i++){
            if (!q.empty() && q.front() <= i - k){
                q.pop();
            }
            if(arr[i] < 0){
                q.push(i);
            }
            if (i >= k -1){
                if (!q.empty()){
                    res.push_back(arr[q.front()]);
                }else {
                    res.push_back(0);
                }
            }
        }
        return res;
    }
};


// Q11. Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> vec;
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                vec.push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            res.push_back(vec);
        }

        return res;
    }
};


// Q12. There are n gas stations along a circular tour. You are given two integer arrays gas[] and cost[], where gas[i] is the amount of gas available at station i and cost[i] is the gas needed to travel from station i to station (i+1). You have a car with an unlimited gas tank and start with an empty tank at some station. Your task is to return the index of the starting station if it is possible to travel once around the circular route in a clockwise direction without running out of gas at any station; otherwise, return -1.

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n = gas.size();
        int balance = 0;
        int deficit = 0;
        int start = 0;
        
        for (int i = 0; i < n; i++){
            balance+=gas[i] - cost[i];
            if (balance < 0){
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }
        
        if (balance + deficit >= 0) return start;
        return -1;
    }
};


// Q13. You are given an m x n grid where each cell can have one of three values: 0 representing an empty cell, 1 representing a fresh orange, or 2 representing a rotten orange. Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        int freshOranges = 0;
        int time = 0;

        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }else if (grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            if (i - 1 >= 0 && !visited[i-1][j] && grid[i-1][j] == 1){
                q.push({{i-1, j}, t + 1});
                visited[i-1][j] = true;
                freshOranges--;

            }
            if (i + 1 < n && !visited[i+1][j] && grid[i+1][j] == 1){
                q.push({{i+1, j}, t + 1});
                visited[i+1][j] = true;
                freshOranges--;

            }
            if (j + 1 < m && !visited[i][j+1] && grid[i][j+1] == 1){
                q.push({{i, j+1}, t + 1});
                visited[i][j+1] = true;
                freshOranges--;

            }
            if (j - 1 >= 0 && !visited[i][j-1] && grid[i][j-1] == 1){
                q.push({{i, j-1}, t + 1});
                visited[i][j-1] = true;
                freshOranges--;

            }
        }

        if (freshOranges > 0) return -1;
        return time;
    }
};


// Q14. Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        queue<int> vec;
        int maxi = 0;
        int i = 0;
        int curSum = 0;
        while(i < k){
            vec.push(arr[i]);
            curSum+=arr[i];
            i++;
        }
        if (k == arr.size()) return curSum;
        maxi = curSum;
        while(i < arr.size()){
            curSum -= vec.front();
            vec.pop();
            vec.push(arr[i]);
            curSum+=arr[i];
            
            maxi = max(maxi, curSum);
            i++;
        }
        return maxi;
    }
};


// Q15. Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int cnt = 0;
        int sum = 0;
        for(int num: arr){
            sum+=num;
            cnt+=mpp[sum - k];
            mpp[sum]++;
        }
        return cnt;
    }
};


// Q16. You are given a string s. You have to find the length of the longest substring with all distinct characters. 

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_set<char> window;
        int left = 0, right = 0;
        int maxLen = 0;
        
        while (right < s.size()) {
            if (window.find(s[right]) == window.end()) {
                window.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                window.erase(s[left]);
                left++;
            }
        }
        
        return maxLen;
    }
};


// Q17. Given a string s consisting of only lowercase alphabets, for each index i in the string (0 ≤ i < n), find the first non-repeating character in the prefix s[0..i]. If no such character exists, use '#'.

class Solution {
  public:
    string firstNonRepeating(string &s) {
        queue<char> q;
        unordered_map<char ,int> mpp;
        string str;
        
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
            if (mpp[s[i]] == 1) q.push(s[i]);
            
            while(!q.empty() && mpp[q.front()] > 1) q.pop();
            
            if (q.empty()){
                str+="#";
            }else {
                str+=q.front();
            }
        }
        return str;
    }
};


Q18. 
