// Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.

class Solution {
public:
    bool canPlace(vector<int>& nums, int minDistance, int cows){
        int n = nums.size();
        int cowsPlace = 1;
        int last = nums[0];
        for(int i = 1; i < n; i++){
            if (nums[i] - last >= minDistance){
                cowsPlace++;
                last = nums[i];
            }
            if (cowsPlace >= cows) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 1;
        int high = nums[n-1] - nums[0];

        while(low <= high){
            int mid = low + (high - low) / 2;
            if (canPlace(nums, mid, k)){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return high;
    }
};


// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k. Return the kth positive integer that is missing from this array.

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low + k;
    }
};


// You are given an integer array bloomDay, an integer m and an integer k. You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden. The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet. Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

class Solution {
public:
    int getBouquets(const vector<int>& bloomDay, int mid, int k) {
        int bouquets = 0;
        int count = 0;
        
        for (int bloom : bloomDay) {
            if (bloom <= mid) {
                count++;
            } else {
                count = 0;
            }
            
            if (count == k) {
                bouquets++;
                count = 0;
            }
        }
        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = (long long)m * (long long)k;
        if (val > bloomDay.size()) return -1;
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int num : bloomDay) {
            high = max(high, num);
            low = min(low, num);
        }
        
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if (getBouquets(bloomDay, mid, k) >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};


// Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.

class Solution {
public:
    int checkRoot(int mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = ans * mid;
            if (ans > m) return 2; 
        }
        if (ans == m) return 1;
        return 0;
    }

    int NthRoot(int N, int M) {
        if (M == 0 || M == 1) return M;
        
        int low = 1;
        int high = M; 

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int check = checkRoot(mid, N, M);

            if (check == 1) {
                return mid;
            } 
            else if (check == 0) {
                low = mid + 1;
            } 
            else {
                high = mid - 1; 
            }
        }
        return -1;
    }
};


// A peak element is an element that is strictly greater than its neighbors. Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks. You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;
        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            if (nums[mid-1] < nums[mid]){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return -1;
    }
};


// Given a sorted array of nums and an integer x, write a program to find the upper bound of x. The upper bound of x is defined as the smallest index i such that nums[i] > x. If no such index is found, return the size of the array.

class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int n = nums.size();
        int ans = n;
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid]<=x){
                low = mid+1;
            }else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};


// Given a sorted array of nums and an integer x, write a program to find the lower bound of x. The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x. If no such index is found, return the size of the array.

class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0;
        int ans = n;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] >= x){
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


// There is an integer array nums sorted in ascending order (with distinct values). Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2]. Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] == target)return mid;
            
            if (nums[low] <= nums[mid]){
                if (target >= nums[low] && target <= nums[mid]){
                    high = mid - 1;
                }else {
                    low = mid + 1;
                }
            }else{
                if (target <= nums[high] && target >= nums[mid]){
                    low = mid + 1;
                }else {
                    high = mid - 1;
                }
            }
            
        }
        return -1;
    }
};


// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int idx = n;
        while(low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid]>=target){
                idx = mid;
                high = mid - 1;
            }else {
                low = mid+1;
            }
        }
        return idx;
    }
};


// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};
