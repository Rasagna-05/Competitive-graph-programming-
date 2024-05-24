class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(root==NULL){
            return result;
        }
        q.push(root);
        int k=0;
        while(!q.empty()){
            vector<int> level;
            vector<int> s;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            if(k%2==0){
                s=level;
            }else{
                int r=level.size();
                for(int i=0;i<r;i++){
                    s.push_back(level[r-1-i]);
                }
            }
            result.push_back(s);
            k=k+1;
        }
        return result;
    }
};
