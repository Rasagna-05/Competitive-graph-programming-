class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    queue<int>q;
	    vector<int>d(V,-1);
	    
	    q.push(0);
	    d[0]=0;
	    while(!q.empty()){
	        int v=q.front();
	        q.pop();
	        for(auto i : adj[v]){
	            if(d[i]==-1){
	                q.push(i);
	                d[i]=d[v]+1;
	            }
	        }
	    }
	    return d[X];
	}
};
