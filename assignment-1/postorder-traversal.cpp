class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversalHelper(root, result);
        return result;
    }

private:
    void postorderTraversalHelper(TreeNode* node, vector<int>& result) {
        if (node == NULL) {
            return;
        }
        postorderTraversalHelper(node->left, result);
        postorderTraversalHelper(node->right, result);
        result.push_back(node->val);
    }
};
