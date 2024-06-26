class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        TreeNode* curr=root;
        if(curr==NULL ){
            return 0;
        }
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL){
            sum+=root->left->val;
        }
        sum+=sumOfLeftLeaves(root->left);
        sum+=sumOfLeftLeaves(root->right);
        
        return sum;
        
        


    }
};
