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

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        //1.Base Case
        if(node==NULL)
        {
            return 0;
        }
        
        //2.Hypothesis
        int leftheight=height(node->left);
        int rightheight=height(node->right);
        
        //3.Induction
        int ans=1+max(leftheight,rightheight);
        return ans;
    }
};