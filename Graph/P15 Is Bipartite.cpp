#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> graph)
{
	int n = graph.size();

	vector<int> colours(n,0);
	queue<int>q;

	//BFS
	for(int i=0;i<n;i++)
	{
		if(colours[i]==0)
		{
			colours[i]=1;
			q.push(i);

			while(q.empty()==false)
			{
				int f = q.front();

				for(auto nbr:graph[f])
				{
					 if (!colors[neighbor])
					 {
	                    colors[neighbor] = colors[temp]^1;
	                    q.push(neighbor);
	                 }
	               
	                else if (colors[neighbor] == colors[temp])
	                {
	                    return false;
	                }
				}

				q.pop();
			}
		}
	}

	return true;
}