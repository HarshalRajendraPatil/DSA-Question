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

// Q7. Given an array arr of integers, find all the elements that occur more than once in the array. If no element repeats, return an empty array.

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

// Q8. Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

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

// Q9. Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays. The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union.

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

// Q10. Given an array, arr of n integers, and an integer element x, find whether element x is present in the array. Return the index of the first occurrence of x in the array, or -1 if it doesn't exist.

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

// Q10. Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.

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




