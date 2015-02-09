struct Node{
    char data;
    Node* pParent;
    Node* pRchild;
    Node* pLchild;
};

// find next in left center right

Node * find_next(Node * current){
    if (current == NULL){
        return NULL;
    }
    Node * next=NULL;
    if ((current->pRchild) != NULL){
        next = current->pRchild;
        while (next->pLchild != NULL){
            next = next->pLchild;
        }
        return (next);
    } else if (current->pParent != NULL ){
        next = current->pParent;
        while ((next != NULL) && (next->pLchild != current)){
            current = next;
            next = next->pParent
        }
    }
    
    return (next);
}