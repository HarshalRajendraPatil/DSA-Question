// You are given an integer array arr of size n which contains both positive and negative integers. Your task is to find the length of the longest contiguous subarray with sum equal to 0. Return the length of such a subarray. If no such subarray exists, return 0.
class Solution {
  public:
    int maxLen(vector<int>& arr) {
      unordered_map<int, int>mpp;
      int sum = 0;
      int lsa = 0;
      for (int i = 0; i < arr.size(); i++){
        sum+=arr[i];
        if (sum == 0){
          lsa = max(lsa, i+1);
        }else{
          int rem = sum;
          if (mpp.find(rem) != mpp.end()){
            lsa = max(lsa, i - mpp[rem]);
          }
        }
        if(mpp.find(sum) == mpp.end()){
          mpp[sum] = i;
        }
      }
      return lsa;
    }
};


// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k. A subarray is a contiguous non-empty sequence of elements within an array.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int cnt = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
            int rem = sum - k;
            if (mpp.find(rem) != mpp.end()){
                cnt += mpp[rem];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};


// Given an array of integers nums, find the next permutation of nums.
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        for (int i = nums.size() - 2; i >= 0; i--){
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        if (idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > idx; i--){
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        reverse(nums.begin() + idx + 1, nums.end());
        return;
    }
};


// Given an m x n matrix, return all elements of the matrix in spiral order.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int top = 0;
        int right = m - 1;
        int bottom = n - 1;

        while(left <= right && top <= bottom){
            for (int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom){
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right){
                for(int i = bottom; i >= top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};


// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers. You should return the array of nums such that the array follows the given conditions: Every consecutive pair of integers have opposite signs. For all integers with the same sign, the order in which they were present in nums is preserved. The rearranged array begins with a positive integer. Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        int i = 0; // +ve
        int j = 0; // -ve

        while(i < nums.size() && nums[i] < 0)i++;
        while(j < nums.size() && nums[j] >= 0)j++;

        while(i < nums.size() && j < nums.size()){
            res.push_back(nums[i]);
            res.push_back(nums[j]);
            i++;
            j++;
            while(i < nums.size() && nums[i] < 0)i++;
            while(j < nums.size() && nums[j] >= 0)j++;
        }

        while(i < nums.size()){
            res.push_back(nums[i]);
            i++;
        }

        while(j < nums.size()){
            res.push_back(nums[j]);
            j++;
        }

        return res;
    }
};


// Given an array arr[] of integers, change the given array such that at any index i it contains the sum of all elements except itself. Simple way arr[i] should be arr[0] + arr[1] ... arr[i-1] + arr[i+1] ... arr[n-1].

class Solution {
  public:

    void sumArray(vector<int> &arr) {
        int sum= 0;
        for (int i = 0; i < arr.size(); i++){
            sum += arr[i];
        }
        for (int i = 0; i < arr.size(); i++){
            arr[i] = sum - arr[i];
        }
    }
};

// You are given an array arr[], and you have to re-construct an array arr[]. The values in arr[] are obtained by doing Xor of consecutive elements in the array.

int* game_with_number(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++){
        arr[i] = arr[i] ^ arr[i + 1];
    }
    return arr;
}

// Given two arrays arr1 and arr2, return the merged array in ascending order containing unique elements.

class Solution {
  public:
    vector<int> mergeNsort(vector<int>& a, vector<int>& b) {
        set<int>s;
        vector<int> ans;
        for (int i = 0; i < a.size(); i++){
            s.insert(a[i]);
        }
        for (int i = 0; i < b.size(); i++){
            s.insert(b[i]);
        }
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
    }
};

// Given an array arr[], check whether it is sorted in non-decreasing order. Return true if it is sorted otherwise false.

class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        for(int i = 0; i < arr.size() - 1; i++){
            if (arr[i] > arr[i + 1]) return false;
        }
        return true;
    }
};

// Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int l = 0;
        int r = arr.size() - 1;
        int pos = -1;
        while(l <= r){
            int mid = (l + (r-l)) / 2;
            if(arr[mid] == k) {
                pos = mid;
                break;
            }
            else if(arr[mid] < k) l = mid + 1;
            else r = mid - 1;
        }
        return pos;
    }
};

// Given an array arr[] of size n, filled with numbers from 1 to n-1 in random order. The array has only one repetitive element. Your task is to find the repetitive element.

class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++){
            mpp[arr[i]]++;
        }
        for(auto it: mpp){
            if(it.second > 1) return it.first;
        }
        return -1;
    }
};

// Given an array arr of integers, find all the elements that occur more than once in the array. If no element repeats, return an empty array.

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int>res;
        unordered_map<int,int>mpp;
        for (auto it: arr){
            mpp[it] ++;
        }
        for (auto it : mpp){
            if(it.second > 1) res.push_back(it.first);
        }
        return res;
    }
};

// Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int cnt = 0;
        for(auto it: arr){
            if(it == target){
                cnt++;
            }
        }
        return cnt;
    }
};

// Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays. The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union.

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> s;
        for (auto it: a){
            s.insert(it);
        }
        for (auto it: b){
            s.insert(it);
        }
        return s.size();
    }
};

// Given an array, arr of n integers, and an integer element x, find whether element x is present in the array. Return the index of the first occurrence of x in the array, or -1 if it doesn't exist.

class Solution {
  public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int search(vector<int>& arr, int x) {
        int pos = -1;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == x){
                pos = i;
                break;
            }
        }
        return pos;
    }
};

// Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int cnt = 0;
        int el = -1;

        for(int i = 0; i < arr.size(); i++){
            if(cnt == 0){
                el = arr[i];
                cnt = 1;
            } else if(arr[i] == el){
                cnt++;
            } else {
                cnt--;
            }
        }
        cnt = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == el) cnt++;
        }

        if(cnt > arr.size() / 2) return el;
        return -1; 
    }
};


// Given a 2D integer array mat[][] and a number x, find whether element x is present in the matrix or not.

class Solution {
  public:
    // Function to search a given integer in a matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        for(auto it: mat){
            for(auto it2: it){
                if(it2 == x) return true;
            }
        }
        return false;
    }
};


// You are given a sorted array arr[] that may contain duplicate elements. Your task is to find the index of the last occurrence of any duplicate element and return the index along with the value of that element. If no duplicate element is found, return [-1, -1].

class Solution {
  public:
    vector<int> dupLastIndex(vector<int>& arr) {
        vector<int> res;
        int idx = -1;
        int el = -1;
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] == arr[i+1]){
                el = arr[i];
                idx = i+1;
            }
        }
        res.push_back(idx);
        res.push_back(el);
        return res;
    }
};


// Given an array arr[] of n positive integers. The task is to find the maximum for every adjacent pairs in the array.

void maximumAdjacent(int sizeOfArray, int arr[]) {
    for(int i = 0; i<sizeOfArray - 1; i++){
        cout << max(arr[i], arr[i+1]) << " ";
    }
}

// Given an integer k and array arr. Your task is to return the position of the first occurrence of k in the given array and if element k is not present in the array then return -1.

class Solution {
  public:
    int search(int k, vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++){
            if(arr[i] == k)return i+1;
        }
        return -1;
    }
};


// Given an array arr, rotate the array by one position in clockwise direction

class Solution {
  public:
    void rotate(vector<int> &arr) {
        int last = arr[arr.size() - 1];
        for (int i = arr.size() - 1; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = last; 
    }
};


// You are given an array arr[], the task is to return a list elements of arr in alternate order (starting from index 0).

class Solution {
  public:
    vector<int> getAlternates(vector<int> &arr) {
        vector<int> res;
        for(int i = 0; i < arr.size(); i+=2){
            res.push_back(arr[i]);
        }
        return res;
    }
};


// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest = arr[0];
        int slar = -1;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > largest){
                slar = largest;
                largest = arr[i];
            }else if(arr[i] > slar && arr[i] < largest){
                slar = arr[i];
            }
        }
        return slar;
    }
};


// Given an array arr[], check whether it is sorted in non-decreasing order. Return true if it is sorted otherwise false.

class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] > arr[i+1]) return false;
        }
        return true;
    }
};


// Given a sorted array arr. Return the size of the modified array which contains only distinct elements.

class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        int j = 0;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] != arr[j]){
                arr[j+1] = arr[i];
                j++;
            }
        }
        return j+1;
    }
};


// Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.
  
class Solution {
  public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rev(vector<int>& arr, int s, int e){
        int i = s;
        int j = e;
        while(i >= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    void rotateArr(vector<int>& arr, int d) {
        d = d % arr.size();
        if (d == 0) return;
        rev(arr, 0, d-1);
        rev(arr, d, arr.size() - 1);
        rev(arr, 0, arr.size() - 1);
    }
};


// You are given an array arr[] of non-negative integers. Your task is to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you should not use extra space for another array.

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int i = 0;
        int j = 0;
        while(j < arr.size()){
            if(arr[j] != 0){
                arr[i++] = arr[j++];
            }else{
                j++;
            }
        }
        while(i < arr.size()){
            arr[i++] = 0;
        }
    }
};


// Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays. The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> se;
        for(int it: a){
            se.insert(it);
        }
        for(int it: b){
            se.insert(it);
        }
        int n = se.size();
        return n;
    }
};


// Given two unsorted integer arrays a[] and b[] each consisting of distinct elements, the task is to return the count of elements in the intersection (or common elements) of the two arrays.

class Solution {
  public:
    int numberofElementsInIntersection(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> mpp;
        int cnt = 0;
        for(int it: a){
            mpp[it]++;
        }
        for(int it: b){
            mpp[it]--;
        }
        for(auto it: mpp){
            if(it.second == 0) cnt++;
        }
        return cnt;
    }
};


// You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int nums = arr.size() + 1;
        long long tsum = (nums * (nums + 1)) / 2;
        long long sum = 0;
        for (auto it: arr){
            sum += it;
        }
        return tsum - sum;
    }
};


// Given a sorted array arr[] of n positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once.

class Solution {
  public:
    int search(int n, int arr[]) {
        int num = 0;
        for(int i = 0; i < n; i++){
            num ^= arr[i];
        }
        return num;
    }
};


// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> mpp;
        int maxLen = 0;
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sum+=arr[i];
            if(sum == k) maxLen = max(maxLen, i+1);
            long long rem = sum - k;
            if(mpp.find(rem) != mpp.end()){
                int len = i - mpp[rem];
                maxLen = max(maxLen, len);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return maxLen;
    }
};
