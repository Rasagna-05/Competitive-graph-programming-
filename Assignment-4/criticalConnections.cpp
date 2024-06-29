class Solution {
private:
int timer=0;
    void dfs(int node,int parent,int tin[],int low[],vector<int>&vis,vector<int>adj[],  vector<vector<int>>&bridges){
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it : adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,tin,low,vis,adj,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({node,it});
                }
            }else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it : connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>bridges;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,-1,tin,low,vis,adj,bridges);
            }
        }
        return bridges;
    }
};
