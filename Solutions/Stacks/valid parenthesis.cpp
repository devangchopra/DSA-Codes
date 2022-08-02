class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>s;
        
        bool b = false;
        
        for(int i=0;i<x.size();i++)
        {
            if(s.empty() or x[i]=='{' or x[i]=='(' or x[i]=='[')
            {
                s.push(x[i]);
            }
            else
            {
                if(x[i] == ')' && s.top() != '(') break;
                if(x[i] == '}' && s.top() != '{') break;
                if(x[i] == ']' && s.top() != '[') break;
                s.pop();
            }
            
            
        }
        if(s.size()==0)
        {
            b=true;
        }
        return b;
    }

};