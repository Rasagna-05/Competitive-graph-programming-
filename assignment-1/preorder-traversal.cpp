class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr= root;
        while(curr!=NULL){
            result.push_back(curr->val);
            if(curr->left==NULL){
                curr=curr->right;
            }else{
                curr=curr->left;
            }
        }
    return result;
};
};
