class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        map<int,int>m;
        queue<Node*>q;
        q.push(root);
        int level=-1;
        
        while(q.size()!=0)
        {
            int n=q.size();
            level++;
            for(int i=1;i<=n;i++)
            {
                Node* front=q.front();
                q.pop();
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
                if(front->left==NULL and front->right==NULL)
                {                        
                    m[level]=front->data;
                    
                }
            }
            
        }
        if(m.size()>1)
        {
            return false;
        }
        else
        {
             return true;
        }
    }
};