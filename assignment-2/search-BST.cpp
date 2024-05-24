class Solution {
public:


    TreeNode* searchBST(TreeNode* root, int n) {
        
        if(root==NULL){
            return NULL;
        }
        if(root->val==n){
            return root;
        }
        if(root->val>n){
            return searchBST(root->left,n);
        }
        
        return searchBST(root->right,n);
    }
};
