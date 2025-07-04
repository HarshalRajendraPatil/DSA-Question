// Q1. Given an integer array arr. For each element in the array, check whether the right adjacent element (on the next immediate position) of the array is smaller. If the next element is smaller, update the current index to that element. If not, then update to -1.

class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        stack<pair<int, int>> st;
        for(int i = arr.size() - 1; i >= 0; i--){
            if(i == arr.size() - 1){
                st.push({arr[i], -1});
            }else{
                if(arr[i] > st.top().first){
                    st.push({arr[i], st.top().first});
                }else{
                    st.push({arr[i], -1});
                }
            }
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = st.top().second;
            st.pop();
        }
    }
};


// Q2. You are given an array arr[], the task is to reverse the array elements in-place by using a stack.

class Solution {
  public:
    void reverseArray(vector<int>& arr) {
        stack<int> st;
        for(int i : arr){
            st.push(i);
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = st.top();
            st.pop();
        }
    }
};


// Q3. Given a stack of integers and Q queries. The task is to perform the operation on stack according to the query.

void insert(stack<int> &s, int x) {
    s.push(x);
}

void remove(stack<int> &s) {
    s.pop();
}

void headOf_Stack(stack<int> &s) {
    int x = s.top();
    cout << x << " " << endl;
}

bool find(stack<int> s, int val) {
    bool exists = false;
    
    stack<int> tempS = s;
    
    while(!tempS.empty()){
        if(tempS.top() == val){
            exists = true;
            break;
        }
        tempS.pop();
    }

    if (exists == true) {
        return true;
    } else {
        return false;
    }
}


// Q4. You are given an integer array arr[]. You need to push the elements of the array into a stack and then print them while popping.

class Solution {
  public:
    // Function to push elements of an array into a stack.
    stack<int> push(vector<int> &arr) {
        int n = arr.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            s.push(arr[i]);
        }
        return s;
    }

    // Function to pop elements from a stack and print them.
    void pop(stack<int> s) {
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
};


// Q5. Given a stack of integers of size N, your task is to complete the function pairWiseConsecutive(), that checks whether numbers in the stack are pairwise consecutive or not. The pairs can be increasing or decreasing, and if the stack has an odd number of elements, the element at the top is left out of a pair. 

bool pairWiseConsecutive(stack<int> s) {
    while(!s.empty()){
        int a = s.top(), b;
        s.pop();
        if(s.size() > 0){
            b = s.top();
            s.pop();
            if ((a - b) > 1 || (a - b) < -1){
                return 0;
            }
        }
    }
    
    
    return 1;
}


// Q6. Given an array of negative and non-negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers, arr[i] and arr[i+1] are either negative or non-negative. And you can do the following operation any number of times until the array becomes beautiful.

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> s;
        for(int i = 0; i < arr.size(); i++) {
            
            
            
            if(!s.empty() && ((s.top() >= 0 && arr[i] < 0) || (s.top() < 0 && arr[i] >= 0))) {
                // Opposite signs → cancel out
                s.pop();
            } else {
                s.push(arr[i]);
            }
        }

        // Now move from stack to vector in correct order
        vector<int> vec(s.size());
        for(int i = s.size() - 1; i >= 0; i--) {
            vec[i] = s.top();
            s.pop();
        }

        return vec;
    }
};


Q7. 

