vector<int> reverseLevelOrder(Node *root)
{
    vector<int>v;
    queue<Node*>pq;
    pq.push(root);
    stack<Node*>s;
    while(pq.size()!=0)
    {
        Node* temp=pq.front();
        pq.pop();
        s.push(temp);
        if(temp->right!=NULL)
        {
            pq.push(temp->right);
        }
        if(temp->left!=NULL)
        {
            pq.push(temp->left);
        }
    }
    
    while(s.size()!=0)
    {
        Node* abc=s.top();
        v.push_back(abc->data);
        s.pop();
    }
    return v;
}