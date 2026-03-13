// Find all valid combinations of k numbers that sum up to n such that the following conditions are true: Only numbers 1 through 9 are used. Each number is used at most once. Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

class Solution {
public:
    void getCombination(vector<vector<int>>&res, vector<int>&seq, vector<int>&nums, int idx, int size, int target, int curSum){
        if (seq.size() == size || idx == nums.size() || curSum >= target){
            if (curSum == target && seq.size() == size){
                res.push_back(seq);
            }
            return;
        }
        seq.push_back(nums[idx]);
        getCombination(res, seq, nums, idx+1, size, target, curSum+nums[idx]);
        seq.pop_back();
        getCombination(res, seq, nums, idx+1, size, target, curSum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4, 5, 6, 7, 8, 9};
        vector<vector<int>>res;
        vector<int>seq;
        getCombination(res, seq, nums, 0, k, n, 0);
        return res;
    }
};


// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

class Solution {
public:
    void getCombination(vector<string>&res, string cur, string digits, int idx, vector<string>&mapping){
        if (idx == digits.size()){
            res.push_back(cur);
            return;
        }
        int digit = digits[idx] - '0';
        string letters = mapping[digit];

        for(int i = 0; i < letters.size(); i++){
            cur+=letters[i];
            getCombination(res, cur, digits, idx + 1, mapping);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>res;
        vector<string>mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string current = "";
        getCombination(res, current, digits, 0, mapping);
        return res;
    }
};


// Given an array nums of n integers. Return array of sum of all subsets of the array nums.

class Solution {
  public:
    void getSubSetSum(vector<int>&res, int idx, int curSum, vector<int>& nums){
        if (idx == nums.size()){
            res.push_back(curSum);
            return;
        }
        getSubSetSum(res, idx+1, curSum+nums[idx], nums);
        getSubSetSum(res, idx+1, curSum, nums);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int>res;
        getSubSetSum(res, 0, 0, nums);
        return res;
    }
};


// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

class Solution {
public:
    void findCombinationSum(vector<vector<int>>& res, vector<int>& seq, int curSum, int idx, int target, vector<int>& candidates){
        if (idx == candidates.size() || curSum >= target){
            if (curSum == target) res.push_back(seq);
            return;
        }
        seq.push_back(candidates[idx]);
        findCombinationSum(res, seq, curSum + candidates[idx], idx, target, candidates);
        seq.pop_back();
        findCombinationSum(res, seq, curSum, idx + 1, target, candidates);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>seq;
        findCombinationSum(res, seq, 0, 0, target, candidates);
        return res;
    }
};


// Given an array of integers nums of unique elements. Return all possible subsets (power set) of the array.

class Solution {
public:	
    vector<vector<int>> generateSequence(vector<vector<int>>& nums, vector<int> seq, int cur, int size, vector<int> ori){
        if (cur == size){
            nums.push_back(seq);
            return nums;
        }
        seq.push_back(ori[cur]);
        generateSequence(nums, seq, cur+1, size, ori);
        seq.pop_back();
        generateSequence(nums, seq, cur+1, size, ori);
        return nums;
    }

    vector<vector<int> > powerSet(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int> seq;
        int cur = 0;
        generateSequence(res, seq, cur, nums.size(), nums);
        return res;
    }
};


// Alice and Bob take turns playing a game, with Alice starting first. Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of: Choosing any x with 0 < x < n  and n % x == 0. Replacing the number n on the chalkboard with n - x. Also, if a player cannot make a move, they lose the game. Return true if and only if Alice wins the game, assuming both players play optimally.

class Solution {
  public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};


// Given an integer n, return the first n elements of [Recaman’s sequence](http://mathworld.wolfram.com/RecamansSequence.html).

class Solution {
  public:
    void getSeries(vector<int>& nums, int n, unordered_set<int>&st){
        if (n <= 0) return;
        int size = nums.size();
        
        int num = nums[size - 1] - size;
        if (num > 0 && st.find(num) == st.end()){
            nums.push_back(num);
            st.insert(num);
        }else{
            nums.push_back(nums[size-1]+size);
            st.insert(nums[size-1]+size);
        }
        
        getSeries(nums, n-1, st);
    }
    vector<int> recamanSequence(int n) {
        vector<int> res = {0};
        unordered_set<int>st = {0};
        getSeries(res, n-1, st);
        return res;
    }
};


// You are playing a game with n people standing in a circle, numbered from 1 to n. Starting from person 1, every kth person is eliminated in a circular fashion. The process continues until only one person remains. Given integers n and k, return the position (1-based index) of the person who will survive.

class Solution {
  public:
    int josephus(int n, int k) {
        if (n == 1) return 1;
        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
};


// You are given a number n. You need to find the sum of digits of n.

class Solution {
  public:
    int sumOfDigits(int n) {
        if (n == 0) return 0;
        return n % 10 + sumOfDigits(n/10);
    }
};


// Implement [pow(x, n)](http://www.cplusplus.com/reference/valarray/pow/), which calculates x raised to the power n (i.e., xn).

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            return 1.0 / solve(x, -N);
        }
        return solve(x, N);
    }

    double solve(double x, long long n) {
        if (n == 0) return 1.0;
        double half = solve(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        }else {
            return x * half * half;
        }
    }
};


// You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).

class Solution {
public:
    void sort(stack<int>& st, int x){
        if (st.empty() || st.top() < x){
            st.push(x);
            return;
        }
        int num = st.top();
        st.pop();
        sort(st, x);
        st.push(num);
    }

    void sortStack(stack<int> &st) {
        if (st.empty()) return;
        int num = st.top();
        st.pop();
        sortStack(st);
        sort(st, num);
    }
};


// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 10^9 + 7.

class Solution {
    int MOD = 1000000007;
public:
    long long power(long long x, long long y) {
        long long res = 1;
        x = x % MOD;
        if (x == 0) return 0;

        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % MOD;
            }
            y = y / 2;
            x = (x * x) % MOD;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long countOf4s = n / 2;
        long long countOf5s = n - countOf4s;
        
        long long ans = (power(4, countOf4s) * power(5, countOf5s)) % MOD;
        return (int)ans;
    }
};


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
