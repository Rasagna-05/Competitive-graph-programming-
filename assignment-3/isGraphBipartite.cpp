class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>color(n,-1);
        for(int j=0;j<n;j++){
            if(color[j]==-1){
                queue<int>q;
        q.push(j);
        color[j]=0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int i:graph[v]){
                
                if(color[i]==-1){
                    color[i]=(!color[v]);
                    q.push(i);
                }else if(color[i]==color[v]){
                    return false;
                }
            }
        }
            }
        }
        
    

        return true;
    }
};
