class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfs(int source , bool* vist , vector<int> adj[] , vector<int> &ans)
	{
	    vist[source]=true;
	    ans.push_back(source);
	    
	    for(auto i:adj[source])
	    {
	        if(!(vist[i]))
	        {
	            dfs(i,vist,adj,ans);
	        }
	    }
	    
	    return;
	    
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    //Source = 0
	    vector<int>ans;
	    bool* vist = new bool[V]{0};
	    dfs(0,vist,adj,ans);
	    return ans;
	}
};