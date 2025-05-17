// Q1. Given two linked lists head1 and head2 with distinct elements, determine the count of all distinct pairs from both lists whose sum equals the given value x.

class Solution {
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        int cnt = 0;
        struct Node* temp1 = head1;
        struct Node* temp2 = head2;
        
        unordered_set<int>s;
        while(temp2){
            s.insert(temp2->data);
            temp2 = temp2->next;
        }
        
        while(temp1){
            if(s.count(x-temp1->data)) cnt++;
            temp1 = temp1->next;
        }
        
        return cnt;
    }
};

// Q2. Given a singly linked list, your task is to remove every kth node from the linked list

class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        if (k == 1) return nullptr;
        struct Node* fast = head;
        struct Node* slow = nullptr;
        int cnt = 1;
        int firstRemoved = 1;
        while(fast){
            if (cnt == k){
                slow->next = fast->next;
                struct Node* temp = fast;
                fast = slow->next;
                delete temp;
                cnt = 0;
            }else{
                slow = fast;
                fast = fast->next;
            }
            cnt++;
        }
        return head;
    }
};

// Q3. Given a Singly Linked List, Delete all alternate nodes of the list ie delete all the nodes present in even positions.

class Solution {
  public:
    void deleteAlt(struct Node *head) {
        if(!head->next) return;
        struct Node* fast = head;
        struct Node* slow = nullptr;
        int cnt = 1;
        int firstRemoved = 1;
        while(fast){
            if (cnt == 2){
                slow->next = fast->next;
                struct Node* temp = fast;
                fast = slow->next;
                delete temp;
                cnt = 0;
            }else{
                slow = fast;
                fast = fast->next;
            }
            cnt++;
        }
    }
};
