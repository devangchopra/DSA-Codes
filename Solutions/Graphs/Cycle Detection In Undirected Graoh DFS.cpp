class Solution {
public:
	// Function to detect cycle in an undirected graph.

	bool contains_cycle(bool* visit, int source , vector<int> adj[],int parent)
	{
		visit[source] = true;

		for(auto nbr:adj[source])
		{
			//if there is any nbr which is already visited
			// i will say cycle is there
			if(!visit[nbr])
			{
				bool nbrFoundACycle = contains_cycle(visit,nbr,adj,source);
				if(nbrFoundACycle)
					return true;
			}
			else if(nbr!=parent)
				return true;
		}

		return false;
	}




	bool isCycle(int V, vector<int> adj[]) {
		// Code here
		bool* visit = new bool[V] {0};
		for (int i = 0; i < V; i++)
		{
			if (visit[i] != 1)
			{
				if (contains_cycle(visit, i, adj,-1)) {
					return true;
				}
			}
		}
		return false;
	}
};