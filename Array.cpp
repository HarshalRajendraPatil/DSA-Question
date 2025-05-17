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
