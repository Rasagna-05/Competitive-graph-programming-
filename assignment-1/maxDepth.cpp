class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans=0;
        if(root==NULL){
            return ans;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;

    }
};
