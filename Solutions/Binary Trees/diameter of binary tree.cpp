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
    //Function to return the diameter of a Binary Tree.
    int height(Node* root)
    {
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
        
    }
    int diameter(Node* root)
    {
        if(root==NULL) return 0;
        int c1=height(root->left)+height(root->right);
        int c2=diameter(root->left);
        int c3=diameter(root->right);
        return max(1+c1,max(c2,c3));
        
    }

};