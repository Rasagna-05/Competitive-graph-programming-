class Solution {
  private:
    int timer=0;
    void dfs(int node,int parent,int tin[],int low[],vector<int>&mark,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        int child=0;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,node,tin,low,mark,vis,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(parent==-1 && child>1){
            mark[node]=1;
        }
        return;
    }
  
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int n=V;
        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<int>mark(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,tin,low,mark,vis,adj);
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(mark[i]==1){
                res.push_back(i);
            }
        }
        if(res.size()==0) return {-1};
        return res;
    }
};
