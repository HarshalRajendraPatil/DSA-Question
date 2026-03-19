// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++){
                TreeNode* top = q.front();
                q.pop();
                temp.push_back(top->val);
                if (top->left != nullptr) q.push(top->left);
                if (top->right != nullptr) q.push(top->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};


// Given a binary tree with root node. Return the In-order,Pre-order and Post-order traversal of the binary tree.

void getInOrder(vector<int>& res, TreeNode* root){
    if (root == nullptr){
        return;
    }
    getInOrder(res, root->left);
    res.push_back(root->data);
    getInOrder(res, root->right);
    return;
}

void getPreOrder(vector<int>& res, TreeNode* root){
    if (root == nullptr){
        return;
    }
    res.push_back(root->data);
    getPreOrder(res, root->left);
    getPreOrder(res, root->right);
    return;
}

void getPostOrder(vector<int>& res, TreeNode* root){
    if (root == nullptr){
        return;
    }
    getPostOrder(res, root->left);
    getPostOrder(res, root->right);
    res.push_back(root->data);
    return;
}

class Solution{
	public:
		vector<vector<int> > treeTraversal(TreeNode* root){
            vector<int> inOrder, preOrder, postOrder;
            getInOrder(inOrder, root);
            getPostOrder(postOrder, root);
            getPreOrder(preOrder, root);
            return {inOrder, preOrder, postOrder};
		}
};
