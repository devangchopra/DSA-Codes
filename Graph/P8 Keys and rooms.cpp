class Solution {
public:
    void dfs(int source , bool* visited ,vector<vector<int>>& rooms)
    {  
        visited[source]=true;
        
        //ut<<"This is my source"<<source<<endl;
            
        vector<int>v=rooms[source];
        
        for(auto i:v)
        {
            if(visited[i]==false)
            {
                dfs(i,visited,rooms);
            }
            
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        //0->n-1
        int n = rooms.size();
        bool * visited = new bool[n]{0};
        dfs(0,visited,rooms);
        
        bool x = true;
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                x=false;
                break;
            }
        }
        
        return x;
        
        
    }
};