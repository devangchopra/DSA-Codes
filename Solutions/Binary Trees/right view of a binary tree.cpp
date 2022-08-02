vector<int> leftView(Node *root)
{
   // Your code here
   if(root==NULL)
   {
       vector<int>v;
       return v;
   }
   vector<int>v;
   queue<Node*>q;
   q.push(root);
   while(q.size()!=0)
   {
       int n=q.size();
       for(int i=1;i<=n;i++)
       {
           Node* temp=q.front();
           q.pop();
           if(i==n)
           {
               v.push_back(temp->data);
           }
           if(temp->left!=NULL)
           {
               q.push(temp->left);
           }
           if(temp->right!=NULL)
           {
               q.push(temp->right);
           }
       }
   }
   return v;
   
}