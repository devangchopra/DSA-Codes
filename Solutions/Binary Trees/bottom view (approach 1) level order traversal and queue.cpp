
vector <int> bottomView(Node *root)
{
  map<int,int>m;
  queue<pair<Node*,int>>q;
  vector<int>v;
  if(!root) return v;
  q.push({root,0});
  while(!q.empty())
  {
    Node* t=q.front().first;
    int h=q.front().second;
    q.pop();
    m[h]=t->data; //update krta jaa rha hai..last walaa will be final ans
    if(t->left) q.push({t->left,h-1});
    if(t->right) q.push({t->right,h+1});

  }
  for(auto x:m)v.push_back(x.second);
  return v;
}