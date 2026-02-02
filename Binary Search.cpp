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
