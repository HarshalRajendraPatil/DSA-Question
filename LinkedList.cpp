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


// Q9. Given two linked lists, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

class Solution {
  public:
    struct Node *rev(Node* head){
        Node* prev = nullptr;
        Node* cur = head;
        while(cur){
            Node* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }
    
    struct Node *mergeResult(Node *node1, Node *node2) {
        struct Node* ll = new Node(-1);
        struct Node* res = ll;
        Node* temp1 = node1;
        Node* temp2 = node2;
        while(temp1 && temp2){
            if (temp1->data > temp2->data){
                res->next = new Node(temp2->data);
                temp2 = temp2->next;
            }else{
                res->next = new Node(temp1->data);
                temp1 = temp1->next;
            }
            res = res->next;
        }
        while(temp1){
            res->next = new Node(temp1->data);
            temp1 = temp1->next;
            res = res->next;
        }
        while(temp2){
            res->next = new Node(temp2->data);
            temp2 = temp2->next;
            res = res->next;
        }
        res = ll;
        ll = res->next;
        delete res;
        ll = rev(ll);
        return ll;
    }
};


// Q10. Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        struct Node* ll = new Node(-1);
        Node* res = ll;
        Node* temp1 = head1;
        Node* temp2 = head2;
        while(temp1 && temp2){
            if (temp1->data > temp2->data){
                res->next = new Node(temp2->data);
                temp2 = temp2->next;
            }else{
                res->next = new Node(temp1->data);
                temp1 = temp1->next;
            }
            res = res->next;
        }
        while(temp1){
            res->next = new Node(temp1->data);
            temp1 = temp1->next;
            res = res->next;
        }
        while(temp2){
            res->next = new Node(temp2->data);
            temp2 = temp2->next;
            res = res->next;
        }
        return ll->next;
    }
};


// Q11. Given a sorted doubly linked list and an element x, you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).

class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr || head->data >= x) {
            newNode->next = head;
            if (head != nullptr) head->prev = newNode;
            return newNode;
        }

        Node* curr = head;

        while (curr->next != nullptr && curr->next->data < x) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        if (curr->next != nullptr) {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr;

        return head;
    }
};


// Q12. Given two linked lists (L1 & L2), your task is to complete the function makeUnion(), which returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        struct Node* res = new Node(-1);
        Node* temp = res;
        set<int>s;
        Node* temp1 = head1;
        while(temp1){
            s.insert(temp1->data);
            temp1 = temp1->next;
        }
        temp1 = head2;
        while(temp1){
            s.insert(temp1->data);
            temp1 = temp1->next;
        }
        for(auto it: s){
            struct Node* newNode = new Node(it);
            temp->next = newNode;
            temp = newNode;
        }
        return res->next;
    }
};


// Q13. Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. The sublists should be made from alternating elements from the original list.

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        if (!head->next){
            return {head, nullptr};
        }
        vector<Node*> res;
        Node* temp = head;
        struct Node* ll1 = new Node(-1);
        struct Node* ll2 = new Node(-1);
        Node* temp1 = ll1;
        Node* temp2 = ll2;
        while(temp){
            temp1->next = new Node(temp->data);
            temp1 = temp1->next;
            if(temp->next) temp = temp->next->next;
            else break;
        }
        temp = head->next;
        while(temp){
            temp2->next = new Node(temp->data);
            temp2 = temp2->next;
            if(temp->next) temp = temp->next->next;
            else break;
        }
        res.push_back(ll1->next);
        res.push_back(ll2->next);
        return res;
    }
};


// Q14. Given a singly linked list. The link list represents a binary number, ie- it contains only 0s and 1s. Find its decimal equivalent.

class Solution {
  public:
    long long unsigned int decimalValue(Node *head) {
        const int MOD = 1000000007;
        long long result = 0;
        while (head) {
            result = (result * 2 + head->data) % MOD;
            head = head->next;
        }
        return result;
    }
};


// Q15. Given a Circular linked list. The task is split into two Circular Linked lists. If there are an odd number of nodes in the given circular linked list then out of the resulting two halved lists, the first list should have one node more than the second list.

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        if (head == NULL)
            return {NULL, NULL};
        Node *fast = head, *slow = head;
        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next->next == head)
            fast = fast->next;
        Node *head1 = head;
        Node *head2 = slow->next;
        fast->next = slow->next;
        slow->next = head;
        return {head1, head2};
    }
};

// Q16. Given a singly linked list. The task is to swap elements in the linked list pairwise. For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.

class Solution {
  public:
    Node* pairWiseSwap(Node* head) {
        if (!head || !head->next) return head;

        Node* newHead = head->next;
        Node* prev = nullptr;
        Node* current = head;

        while (current && current->next) {
            Node* nextPair = current->next->next;
            Node* second = current->next;

            second->next = current;
            current->next = nextPair;

            if (prev) {
                prev->next = second;
            }

            prev = current;
            current = nextPair;
        }

        return newHead;
    }
};

// Q17. Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        Node* temp = first;
        long long MOD = 1000000007;
        long long num1 = 0;
        long long num2 = 0;
        while(temp){
            num1 = num1 * 10 + temp->data;
            temp = temp->next;
        }
        temp = second;
        while(temp){
            num2 = num2 * 10 + temp->data;
            temp = temp->next;
        }

        long long ans = (num1*num2)%MOD;
        return ans;
    }
};

// Q18. Given a linked list and a number k. You have to reverse the first part of the linked list with k nodes and the second part with n-k nodes.

class Solution {
  public:
    Node* rev(Node* head){
        Node* cur = head;
        Node* prev = nullptr;
        while(cur){
            Node* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }
    
    Node *reverse(Node *head, int k) {
        Node* slow = nullptr;
        Node* fast = head;
        while(k > 0){
            k--;
            slow = fast;
            fast = fast->next;
        }
        Node* head1 = head;
        Node* head2 = fast;
        slow->next = nullptr;
        
        head1 = rev(head1);
        head2 = rev(head2);
        slow = head1;
        while(slow->next){
            slow = slow->next;
        }
        slow->next = head2;
        return head1;
    }
};

// Q19. Given the head of two singly linked lists, return the point where these two linked lists intersect.

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        int l1 = 0;
        int l2 = 0;
        Node* temp = head1;
        while(temp){
            l1++;
            temp = temp->next;
        }
        temp = head2;
        while(temp){
            l2++;
            temp = temp->next;
        }
        int diff = abs(l1-l2);
        if(l2>l1){
            temp = head2;
            while(diff>0){
                diff--;
                temp = temp->next;
            }
            head2 = temp;
        }else{
            temp = head1;
            while(diff>0){
                diff--;
                temp = temp->next;
            }
            head1 = temp;
        }
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
            
        }
        return temp1;
    }
};

// Q20. Given the head of a singly linked list, your task is to left rotate the linked list k times.

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || !head->next || k == 0) return head;

        Node* last = head;
        int nodes = 1;

        while (last->next) {
            last = last->next;
            nodes++;
        }

        k = k % nodes;
        if (k == 0) return head;

        Node* temp = head;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }

        Node* newHead = temp->next;
        temp->next = nullptr;
        last->next = head;

        return newHead;
    }
};


// Q21. Given the head of a linked list, the task is to find the middle. For example, the middle of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle.

class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        if (!head) return 0;
        

        Node* slow = head;
        Node* fast = head;
        int cnt=0;

        // Move fast by 2 steps and slow by 1 step
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            cnt++;
        }

        // When fast reaches the end, slow is at the middle
        return slow->data;
    }
};


// Q22. Given an array of integer arr. Your task is to construct the linked list from arr & return the head of the linked list.

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* ll = new Node(-1);
        Node* temp = ll;
        for(auto i: arr){
            temp->next = new Node(i);
            temp = temp->next;
        }
        return ll->next;
    }
};
