    void traversetree(Node* root,int d,map<int,vector<int>>&m)
    {
        if(root==NULL)
        {
            return;
        }
        m[d].push_back(root->data);
        traversetree(root->left,d-1,m);
        traversetree(root->right,d+1,m);
        
    }
    vector<int> verticalview(Node *root)
    {
        //Your code here
        map<int,vector<int>>m;
        int d=0;
        traversetree(root,d,m);
        
        //keys are sorted
        vector<int>v;
        
        for(auto p:m)
        {
            int key=p.first;
            vector<int>line=p.second;
            for(auto d:line)
            {
                v.push_back(d);
            }
            
        }
        return v;
    }


