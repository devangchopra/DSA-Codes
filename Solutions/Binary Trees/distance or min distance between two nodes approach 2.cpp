Node* lca(Node* root,int a,int b)
{
    if(!root) return NULL;
    if(root->data==a or root->data==b) return root;
    Node* l=lca(root->left,a,b);
    Node* r=lca(root->right,a,b);
    if(l and r) return root;
    if(l) return l;
    return r;
}

int solve(Node* root,int val)
{
    if(!root) return 0;
    if(root->data==val) return 1;
    int a=solve(root->left,val);
    int b=solve(root->right,val);
    if(!a and !b) return 0;
    else return a+b+1;
}

int findDist(Node* root, int a, int b) {
    // Your code here
    Node* la=lca(root,a,b);
    int x=solve(la,a);
    int y=solve(la,b);
    return x+y-2;
}