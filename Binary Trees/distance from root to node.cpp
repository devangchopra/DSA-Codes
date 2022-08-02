int findDistance(Node *root, int x)
{
    // Base case
    if (root == NULL)
      return -1;
 
    // Initialize distance
    int dist = -1;
 
    // Check if x is present at root or in left
    // subtree or right subtree.
    if ((root->data == x) ||
        (dist = findDistance(root->left, x)) >= 0 ||
        (dist = findDistance(root->right, x)) >= 0)
        return dist + 1;
 
    return dist;
}