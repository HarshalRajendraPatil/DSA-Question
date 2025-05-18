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

// Q4. Given a head singly linked list of positive integers. The task is to check if the given linked list is palindrome or not.

class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        while (head) {
            Node* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;

        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalfStart = reverse(slow->next);

        Node* firstHalf = head;
        Node* secondHalf = secondHalfStart;
        bool isPalin = true;
        while (secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        slow->next = reverse(secondHalfStart);

        return isPalin;
    }
};

// Q5. Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.

class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node *compute(Node *head) {
        if (!head || !head->next) return head;

        head = reverse(head);

        Node* curr = head;
        int maxVal = curr->data;
        while (curr && curr->next) {
            if (curr->next->data < maxVal) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
                maxVal = curr->data;
            }
        }

        head = reverse(head);

        return head;
    }
};

// Q6. Given a head of the singly linked list. If a loop is present in the list then return the first node of the loop else return NULL.

class Solution {
  public:
    Node* findFirstNode(Node* head) {
        if(head->next == head) return head;
        if(!head->next) return nullptr;
        struct Node* fast = head;
        struct Node* slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            };
        }
        return nullptr;
    }
};

// Q7. Given a singly linked list and a number k. Find the (n/k)th element, where n is the number of elements in the linked list. We need to consider ceil value in case of decimals.

class Solution {
  public:
    int fractional_node(struct Node *head, int k) {
        int nodes = 0;
        Node* temp = head;
        while(temp){
            nodes++;
            temp = temp->next;
        }
        int idx = (nodes+k-1)/k;
        temp = head;
        while(idx > 1){
            temp = temp->next;
            idx--;
        }
        return temp->data;
    }
};

// Q8. Given two strings, head1 and head2, represented as linked lists where each character is stored in a node's data field, complete the function compare() that mimics the behavior of strcmp(). Specifically, the function should return:
// 0 if both strings are identical,
// 1 if the first linked list is lexicographically greater, and
// -1 if the second linked list is lexicographically greater.

class Solution {
  public:
    int compare(Node *head1, Node *head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;
        int res = 0;
        while(temp1 && temp2){
            if(temp1->data == temp2->data) res = 0;
            else if(temp1->data > temp2->data) {res = 1;
                return res;
            }
            else {res = -1; return res;}
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1) res = 1;
        if(temp2) res = -1;
        return res;
    }
};
