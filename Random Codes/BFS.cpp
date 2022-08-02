
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        bool* visited = new bool[V]{0};
        
        queue<int>q;
        q.push(0);
        visited[0]=true;
        
        while(q.empty()==false)
        {
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto nbr:adj[t])
            {
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
        
        return ans;
    }
};