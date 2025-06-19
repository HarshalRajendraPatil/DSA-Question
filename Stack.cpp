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
