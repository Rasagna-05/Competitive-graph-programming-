int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>>adjList(A+1);
    for(int i=0;i<B.size();i++){
        int u=B[i][0];
        int v=B[i][1];
        adjList[u].push_back(v);
        
    }
    queue<int>q;
    vector<int>d(A+1);
    vector<bool>vis(A+1,false);
    q.push(1);
    d[1]=0;
    vis[1]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto i : adjList[v]){
            if(!vis[i]){
                q.push(i);
                d[i]=d[v]+1;
                vis[i]=true;
            }
        }
    }
    
    if(vis[A]){
        return 1;
    } return 0;
    
}
