#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        vector<int>v;
      queue<Node*>pending_queue;
      pending_queue.push(node);
      while(pending_queue.size()!=0)
      {
          Node* front=pending_queue.front();
          pending_queue.pop();
          v.push_back(front->data);
          if(front->left!=NULL)
          
          {
              pending_queue.push(front->left);
          }
          if(front->right!=NULL)
          {
             pending_queue.push(front->right); 
          }
          
          
      }
      return v;
    }
};