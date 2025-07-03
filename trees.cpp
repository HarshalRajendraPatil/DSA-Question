// Q1. Given a binary tree, find its preorder traversal.

class Solution {
  public:

    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preorder(Node* root) {
        if (root == nullptr) return {};
        vector <int> ans;
        stack <Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* up = s.top();
            s.pop();
            ans.push_back(up->data);
            if(up->right) s.push(up->right);
            if(up->left) s.push(up->left);
        }
    }
};


// Q2. Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

class Solution {
  public:
    int minValue(Node* root) {
        int mini = INT_MAX;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* up = s.top();
            s.pop();
            mini = min(mini, up->data);
            if(up->right) s.push(up->right);
            if(up->left) s.push(up->left);
        }
        return mini;
    }
};


// Q3. Given a binary tree, find the Postorder Traversal of it and return a list containing the postorder traversal of the given tree.

class Solution {
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        
        vector<int> leftSubtree = postOrder(root->left);
        vector<int> rightSubtree = postOrder(root->right);
        
        
        ans.insert(ans.end(), leftSubtree.begin(), leftSubtree.end());
        ans.insert(ans.end(), rightSubtree.begin(), rightSubtree.end());
        ans.push_back(root->data);
        
        return ans;
    }
};


// Q4. Given a Binary Tree of size n, You have to count leaves in it. For example, there are two leaves in the following tree

class Solution {
  public:
  
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        int leafNodes = 0;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* up = q.front();
            q.pop();
            if(up->left == nullptr && up->right == nullptr) leafNodes++;
            if(up->left) q.push(up->left);
            if(up->right) q.push(up->right);
        }
        return leafNodes;
    }
};


// Q5. Given a binary tree, you have to return the size of it. Size of binary tree is defined as number of nodes in it.

class Solution {
  public:
    int inorder(Node* root){
        if(root == nullptr) return 0;
        
        int a = inorder(root->left);
        int b = inorder(root->right);
        return 1 + a + b;
    }
    int getSize(Node* node) {
        int size = inorder(node);
        return size;
        
    }
};


// Q6. Given a binary tree, find the sum of values of all the nodes. 

class Solution {
  public:
    int inorder(Node* root){
        if(root == nullptr) return 0;
        
        int a = inorder(root->left);
        int b = inorder(root->right);
        return root->data + a + b;
    }
  
    int sumBT(Node* root) {
        int sum = inorder(root);
        return sum;
    }
};


// Q7. Given a Binary Tree of size n, your task is to return the count of all the non-leaf nodes of the given binary tree.

class Solution {
  public:
    int inorder(Node* root){
        if(root == nullptr) return 0;
        
        int a = inorder(root->left);
        int b = inorder(root->right);
        
        if(root->left != nullptr || root->right != nullptr){
            return 1 + a + b;
        }else{
            return a + b;
        }
    }
  
    int countNonLeafNodes(Node* root) {
        int nodes = inorder(root);
        return nodes;
    }
};


Q8. Given a binary tree, find the sum of values of all the leaf nodes. 

class Solution {
  public:
    int inorder(Node* root){
        if(root == nullptr) return 0;
        
        int a = inorder(root->left);
        int b = inorder(root->right);
        
        if(root->left == nullptr && root->right == nullptr){
            return root->data + a + b;
        }else{
            return a + b;
        }
    }
  
    int leafSum(Node* root) {
        int sum = inorder(root);
        return sum;
    }
};
