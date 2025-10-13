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


// Q18. You are given an integer array arr[]. Your task is to perform the following operations: The function _push() takes the array as parameters and returns a queue formed using the array. The function _pop(), takes the queue as the input parameter and prints the queue elements.

queue<int> _push(vector<int> &arr) {
    queue<int> q;
    for(int a: arr){
        q.push(a);
    }
    return q;
}

void _pop(queue<int> &q) {
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

// Q19. Given a queue of integers and Q queries. The task is to perform operations on the queue according to the query. Queries are as: i x : adds element x in the queue from the rear. r : removes the front element of the queue. h : returns the front element. f y : check if the element y is present or not in the queue. Return true if present, else false.

class Solution {
  public:

    // Function to push an element in queue.
    void enqueue(queue<int> &q, int x) {
        q.push(x);
    }

    // Function to remove front element from queue.
    void dequeue(queue<int> &q) {
        q.pop();
    }

    // Function to find the front element of queue.
        
    int front(queue<int> &q) {
        return q.front();
    }

        
    // Function to find an element in the queue.
    bool find(queue<int> q, int y) {
        while(!q.empty()){
            int a = q.front();
            q.pop();
            if (a == y) return true;
        }
        return false;
    }
};


// Q20. Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order. Only following standard operations are allowed on queue. enqueue(x) : Add an item x to rear of queue. dequeue() : Remove an item from front of queue. size() : Returns number of elements in queue. front() : Finds front item.

class Solution {
  public:
    queue<int> modifyQueue(queue<int> &q, int k) {
        stack<int>st;
        int i = k;
        while(i > 0){
            st.push(q.front());
            q.pop();
            i--;
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        for(int j = 0; j < q.size() - k; j++){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};


// Q21. A deque is a double-ended queue that allows enqueue and dequeue operations from both the ends. Given a deque and q queries. The task is to perform some operation on dequeue according to the queries as given below: 1. pb: query to push back the element x. 2. pf: query to push element x(given with query) to the front of the deque. 3. pp_b(): query to delete element from the back of the deque. 4. f: query to return a front element from the deque.

class Solution {
  public:
    // 1️⃣ Push element x to the back of deque
    void pb(deque<int>& dq, int x) {
        dq.push_back(x);
    }

    // 2️⃣ Pop element from the back of deque
    void ppb(deque<int>& dq) {
        if (!dq.empty())  // ✅ safety check to avoid runtime error
            dq.pop_back();
    }

    // 3️⃣ Get front element of deque
    int front_dq(deque<int>& dq) {
        if (!dq.empty())  // ✅ safety check
            return dq.front();
        return -1;  // or throw exception depending on requirement
    }

    // 4️⃣ Push element x to the front of deque
    void pf(deque<int>& dq, int x) {
        dq.push_front(x);
    }
};


// Q22. n people from 1 to n are standing in the queue at a movie ticket counter. It is a weird counter, as it distributes tickets to the first k people and then the last k people and again first k people and so on, once a person gets a ticket moves out of the queue. The task is to find the last person to get the ticket.

class Solution {
  public:
    int distributeTicket(int n, int k) {
        deque<int> dq;
        for (int i = 1; i <= n; i++)
            dq.push_back(i);

        bool frontTurn = true;

        while (dq.size() > 1) {
            int take = min(k, (int)dq.size() - 1);

            if (frontTurn) {
                for (int i = 0; i < take; i++)
                    dq.pop_front();
            } else {
                for (int i = 0; i < take; i++)
                    dq.pop_back();
            }

            frontTurn = !frontTurn;
        }

        return dq.front();
    }
};


// Q23. Implement a class myQueue that supports following operations: void enqueue(int x): Insert an element x at the end of the queue. void dequeue(): Remove the element from the front of the queue. int getFront(): Return the element at the front of the queue. int getRear(): Return the element at the rear end of the queue. bool isEmpty(): Return true if the queue is empty, otherwise false. int size(): Return the number of elements currently in the queue.

class myQueue {
    queue<int> q;
  public:
    void enqueue(int x) {
        q.push(x);
    }

    void dequeue() {
        if (!q.empty()) q.pop();
    }

    int getFront() {
        return q.front();
    }

    int getRear() {
        return q.back();
    }

    bool isEmpty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }
};


// Q24. Implement a Queue using stacks. You are allowed to use only stack data structures to implement the queue. The Queue must support the following operations: (i) enqueue(x): Insert an element x at the rear of the queue. (ii) dequeue(): Remove the element from the front of the queue. (iii) front(): Return the front element if the queue is not empty, else return -1. (iv) size(): Return the number of elements currently in the queue.

class myQueue {
    stack<int>s1, s2;

  public:
    myQueue() {
    }

    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int front() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()){
            return -1;
        }else {
            return s2.top();
        }
    }

    int size() {
        return s1.size() + s2.size();
    }
};


// Q25. Given a Deque deq containing non-negative integers. Complete below functions depending type of query as mentioned and provided to you (indexing starts from 0): 1. eraseAt(x): this function should remove the element from specified position x in deque. 2. eraseInRange(start, end): this function should remove the elements in range start (inclusive), end (exclusive) specified in the argument of the function. Note: If start is equal to end then simply return. 3. eraseAll(): remove all the elements from the deque.

class Solution {
  public:
    void eraseAt(deque<int> &deq, int x) {
        for (int i = 0; i < x; i++){
            deq.push_back(deq.front());
            deq.pop_front();
        }
        deq.pop_front();
        for (int i = 0; i < x; i++){
            deq.push_front(deq.back());
            deq.pop_back();
        }
    }

    void eraseInRange(deque<int> &deq, int start, int end) {
        if (start == end) return;
        for (int i = 0; i < start; i++){
            deq.push_back(deq.front());
            deq.pop_front();
        }
        for(int i = start; i < end; i++){
            deq.pop_front();
        }
        for (int i = 0; i < start; i++){
            deq.push_front(deq.back());
            deq.pop_back();
        }
    }

        
    void eraseAll(deque<int> &deq) {
        while(!deq.empty()){
            deq.pop_back();
        }
    }
};


// Q26. Given an array arr[] which contains data of N nodes of Complete Binary tree in level order fashion. The task is to print the level order traversal in sorted order.

class Solution {
  public:
    vector<vector<int>> binTreeSortedLevels(int arr[], int n) {
        vector<vector<int>>res;
        queue<int> q;
        for(int i = 0; i < n; i++){
            q.push(arr[i]);
        }
        int power = 0;
        while(!q.empty()){
            vector<int>temp;
            int size = pow(2, power);
            power++;
            while(size > 0){
                size--;
                if(!q.empty()){
                    temp.push_back(q.front());
                    q.pop();
                }else {
                    break;
                }
            }
            sort(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
};


// Q27. Given a head  Linked List . Construct the complete binary tree from the given Linked List and return the root of the tree. The result will be judged by printing the level order traversal of the binary tree.

class Solution {
  public:
    Node* linkedListToBinaryTree(NodeLL* head) {
        if (!head) return nullptr;

        // Step 1: Create the root node using first element
        Node* root = new Node(head->data);
        head = head->next;

        // Step 2: Create a queue for level order construction
        queue<Node*> q;
        q.push(root);

        // Step 3: Construct tree in level order
        while (head) {
            // Take the front node as parent
            Node* parent = q.front();
            q.pop();

            // Create left child
            Node* leftChild = new Node(head->data);
            parent->left = leftChild;
            q.push(leftChild);
            head = head->next;

            if (!head) break; // no more nodes

            // Create right child
            Node* rightChild = new Node(head->data);
            parent->right = rightChild;
            q.push(rightChild);
            head = head->next;
        }

        return root;
    }
};


// Q28. Given a Binary Tree, check whether the given Binary Tree is Complete Binary Tree or not. A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes should be as much close to left as possible.
    
class Solution {
  public:
    bool isCompleteBT(Node* root) {
        if (!root) return true;

        queue<Node*> q;
        q.push(root);

        bool nullSeen = false;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                nullSeen = true;
            } else {
                if (nullSeen)
                    return false; // non-null node after a null — violates completeness
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return true;
    }
};


// Q29. In the game of Restricted Pacman, an infinite linear path is given. Pacman has to start at position 0 and eat as many candies as possible. In one move he can only jump a distance of either m or n.  If m and n are coprime numbers, find how many candies will be left on the board after the game is over.

class Solution {
  public:
    int findHCF(int a, int b){
        if (b == 0) return a;
        return findHCF(b, a % b);
    }
    
    int candies(int m, int n) {
        if (findHCF(m, n) != 1) return 0;
        return ((m-1) * (n-1)) / 2;
    }
};


// Q30. Design a SpecialQueue data structure that functions like a normal queue but with additional support for retrieving the minimum and maximum element efficiently. The SpecialQueue must support the following operations: enqueue(x): Insert an element x at the rear of the queue. dequeue(): Remove the element from the front of the queue. getFront(): Return the front element without removing. getMin(): Return the minimum element in the queue in O(1) time. getMax(): Return the maximum element in the queue in O(1) time. There will be a sequence of queries queries[][]. The queries are represented in numeric form: 1 x : Call enqueue(x), 2:  Call dequeue(), 3: Call getFront(), 4: Call getMin(), 5: Call getMax(). The driver code will process the queries, call the corresponding functions, and print the outputs of getFront(), getMin(), getMax() operations. You only need to implement the above five functions. Note: It is guaranteed that all the queries are valid.

class SpecialQueue {
    queue<int> q;
    deque<int> minDq, maxDq;

  public:
    void enqueue(int x) {
        q.push(x);

        while (!minDq.empty() && minDq.back() > x)
            minDq.pop_back();
        minDq.push_back(x);

        while (!maxDq.empty() && maxDq.back() < x)
            maxDq.pop_back();
        maxDq.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return;
        int front = q.front();
        q.pop();

        if (!minDq.empty() && minDq.front() == front)
            minDq.pop_front();

        if (!maxDq.empty() && maxDq.front() == front)
            maxDq.pop_front();
    }

    int getFront() {
        if (q.empty()) return -1;
        return q.front();
    }

    int getMin() {
        if (minDq.empty()) return -1;
        return minDq.front();
    }

    int getMax() {
        if (maxDq.empty()) return -1;
        return maxDq.front();
    }
};


// Q31. You are given two integers n and k. Your task is to implement a class kQueues that uses a single array of size n to simulate k independent queues. The class should support the following operations: enqueue(x, i) → Adds the element x into the i-th queue. dequeue(i) → Removes the front element from the i-th queue and returns it. Returns -1 if the queue is empty. isEmpty(i) → Returns true if i-th queue is empty, else return false. isFull() → Returns true if the array is completely full and no more elements can be inserted, otherwise false.

#include <bits/stdc++.h>
using namespace std;

class kQueues {
    int n, k;
    int *arr;     
    int *front;   
    int *rear;    
    int *next;    
    int freeSpot; 

  public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        for (int i = 0; i < k; i++) {
            front[i] = rear[i] = -1;
        }

        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    void enqueue(int x, int i) {
        if (isFull()) return; 

        int index = freeSpot;
        freeSpot = next[index];        
        if (front[i] == -1)            
            front[i] = index;
        else
            next[rear[i]] = index;     

        next[index] = -1;
        rear[i] = index;               
        arr[index] = x;                
    }

    int dequeue(int i) {
        if (isEmpty(i)) return -1;

        int index = front[i];          
        front[i] = next[index];        

        if (front[i] == -1)
            rear[i] = -1;

        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    bool isEmpty(int i) {
        return front[i] == -1;
    }

    bool isFull() {
        return freeSpot == -1;
    }
};
