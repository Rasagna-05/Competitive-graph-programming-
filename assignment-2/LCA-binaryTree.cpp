class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)  {
        
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right==NULL){
            return left;
        }
        if(right!=NULL && left==NULL){
            return right;
        }
        if(lowestCommonAncestor(root->left,p,q)==p && lowestCommonAncestor(root->right,p,q)==q){
            return root;
        }
        if(lowestCommonAncestor(root->left,p,q)==q && lowestCommonAncestor(root->right,p,q)==p){
            return root;
        }

        return NULL;
    }
};
