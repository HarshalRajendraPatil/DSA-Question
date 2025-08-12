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
