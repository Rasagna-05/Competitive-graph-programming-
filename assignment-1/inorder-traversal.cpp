class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        TreeNode* pre;
        while (curr != NULL) {
            if (curr->left == NULL) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                pre = curr->left;
                while (pre->right != NULL && pre->right != curr) {
                    pre = pre->right;
                }
                if (pre->right == NULL) {
                    pre->right = curr;
                    curr = curr->left;
                }
                else {
                    pre->right = NULL;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};
