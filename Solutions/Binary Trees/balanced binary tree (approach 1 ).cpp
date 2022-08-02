int height(Node* root)
{
    if(root==NULL) return 0;
    else
    {
        return 1+max(height(root->left),height(root->right));
    }
}



bool isBalanced(Node *root)
{
    //  Your Code here
    //Base Case
    if(root==NULL) return true;
    
    //Hypothesis
    bool a= isBalanced(root->left);
    bool b= isBalanced(root->right);
    
    //Induction or small calculation
    if(!(abs(height(root->left)-height(root->right))<=1)) return false;
    else
    {
        return a  and b;
    }
}
