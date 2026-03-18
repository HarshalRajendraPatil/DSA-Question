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
