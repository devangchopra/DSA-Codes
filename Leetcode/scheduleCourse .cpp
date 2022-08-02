#include<bits/stdc++.h>
using namespace std;
bool sortcol( const vector<int>& v1,const vector<int>& v2 )
{
    return v1[1] < v2[1];
}
class Solution {
        public:
            int scheduleCourse(vector<vector<int>>& courses) 
            {       
                sort(courses.begin(),courses.end(),sortcol);
                priority_queue<int> q;
                int x=0;

                for(int i=0;i<courses.size();i++)
                {
                    if(x+courses[i][0]<=courses[i][1])
                    {
                        x=x+courses[i][0];
                        q.push(courses[i][0]);
                    }

                    else if(!q.empty() and q.top() > courses[i][0])
                    {
                        int y = q.top();
                        q.pop();
                        
                        x=y-x;
                        x+=courses[i][0];
                        q.push(courses[i][0]);
                    }
                }
                cout<<q.size();
            }
    
};
int main()
{
    Solution obj;
    vector<vector<int>> courses ={{5,5},{4,6},{2,6}};
    obj.scheduleCourse(courses);
    
}