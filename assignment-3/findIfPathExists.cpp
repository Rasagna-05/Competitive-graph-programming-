class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adjList(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int>d(n,-1);
        queue<int>q;
        q.push(source);
        d[source]=0;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int i : adjList[v]){
                if(d[i]==-1){
                    q.push(i);
                    d[i]=d[v]+1;
                }
            }
        }
        if(d[destination]==-1){
            return false;
        }
        return true;

    }
};
