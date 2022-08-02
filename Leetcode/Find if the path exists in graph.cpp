/*
Ques : 
https://leetcode.com/problems/find-if-path-exists-in-graph/
*/

class Solution {
public:
	bool validPath(int n, vector<vector<int>>& edges, int start, int end) {

		list<int> l[n];

		for (int i = 0; i < edges.size(); i++) {
			int x = edges[i][0];
			int y = edges[i][1];
			l[x].push_back(y);
			l[y].push_back(x);
		}


		// BFS
		queue<int> q;
		bool visited[n];
        for(int i=0;i<n;i++)
            visited[i]=0;
		q.push(start);
		visited[start] = 1;
		while (!q.empty())
		{
			int top = q.front();
			q.pop();
			if (top == end)
				return true;

			for(auto nbr:l[top])
			{
				if(visited[nbr]==false)
				{
					visited[nbr]=true;
					q.push(nbr);
				}
			}
		}
		return false;
	}
};