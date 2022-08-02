vector<int>* RootToNodePath(Node* root, int a)
{
    if(root == NULL)
    return NULL;
    
    if(root->data == a)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    
    vector<int>* leftPath = RootToNodePath(root->left, a);
    if(leftPath != NULL)
    {
        leftPath->push_back(root->data);
        return leftPath;
    }
    
    vector<int>* RightPath = RootToNodePath(root->right,a);
    if(RightPath != NULL)
    {
        RightPath->push_back(root->data);
        return RightPath;
    }
    else
    return NULL;
}

int findDist(Node* root, int a, int b) {
   vector<int>* RootToNodePathA = new vector<int>();
   vector<int>* RootToNodePathB = new vector<int>();
   RootToNodePathA = RootToNodePath(root ,a);
   RootToNodePathB = RootToNodePath(root ,b);
   int i = RootToNodePathA->size() -1;
   int j = RootToNodePathB->size() -1;
   while( i>=0 && j>=0 )
   {
    if( RootToNodePathA->at(i) != RootToNodePathB->at(j) )
    break;
    i--;
    j--;
   }
   
   i++;
   j++;
   delete RootToNodePathA;
   delete RootToNodePathB;
   
   return i+j;
    
}