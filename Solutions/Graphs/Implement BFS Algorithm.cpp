class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int>v;
	    queue<int>q;
	    bool* visited=new bool[V]{0};
	    q.push(0);
	    visited[0]=true;
	    
	    while(q.empty()==false)
	    {
	        int f = q.front();
	        v.push_back(f);
	        q.pop();
	        
	        for(auto i:adj[f])
	        {
	            if(visited[i]==false)
	            {
	                q.push(i);
	                visited[i]=true;
	            }
	            
	        }
	    }
	    
	    return v;
	}
};