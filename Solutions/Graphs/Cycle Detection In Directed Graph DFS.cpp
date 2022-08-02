class Solution {
public:

	bool dfs(int node, vector<bool> &visited, vector<bool> &stack, vector<int> &adj[])
	{
		visited[node] = true;
		stack[node] = true;

		for (int nbr : adj[node])
		{
			if (stack[nbr] == true)
				return true;

			else if (visited[nbr] == false)
			{
				bool nbrFoundACycle = dfs(nbr, visited, stack, adj);
				if (nbrFoundACycle)
					return true;
			}
		}

		stack[node] = false;
		return false;
	}



	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		// code here

		vector<bool> visited(V, false);
		vector<bool> stack(V, false);

		for (int i = 0; i < V; i++)
		{
			if (!visited[i])
			{
				if (dfs(i, visited, stack, adj))
				{
					return true;
				}
			}
		}

		return false;
	}
};