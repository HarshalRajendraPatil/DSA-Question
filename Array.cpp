// Q1. Given an array arr[] of integers, change the given array such that at any index i it contains the sum of all elements except itself. Simple way arr[i] should be arr[0] + arr[1] ... arr[i-1] + arr[i+1] ... arr[n-1].

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

// Q2. You are given an array arr[], and you have to re-construct an array arr[]. The values in arr[] are obtained by doing Xor of consecutive elements in the array.

int* game_with_number(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++){
        arr[i] = arr[i] ^ arr[i + 1];
    }
    return arr;
}

// Q3. Given two arrays arr1 and arr2, return the merged array in ascending order containing unique elements.

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

// Q4. Given an array arr[], check whether it is sorted in non-decreasing order. Return true if it is sorted otherwise false.

class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        for(int i = 0; i < arr.size() - 1; i++){
            if (arr[i] > arr[i + 1]) return false;
        }
        return true;
    }
};

// Q5. Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.

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

// Q6. Given an array arr[] of size n, filled with numbers from 1 to n-1 in random order. The array has only one repetitive element. Your task is to find the repetitive element.

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
