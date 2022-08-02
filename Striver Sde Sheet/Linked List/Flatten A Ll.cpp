Node* merge(Node* a, Node* b) {
    Node* res = new Node(0);
    Node* temp = res;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
        temp->next = NULL;
    }
    if(a){
        temp->child=a;
    }
    if(b){
        temp->child=b;
    }
    temp->next = NULL;
    return res->child;

}



Node* flattenLinkedList(Node* root) {
    if (root == NULL || root->next == NULL) {
        return root;
    }
    root->next = flattenLinkedList(root->next);
    // merging two linked-list
    root = merge(root, root->next);
    return root;
}