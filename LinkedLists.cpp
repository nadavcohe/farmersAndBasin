struct Node{
    int data;
    Node* next;
};

Node* switch_node(Node **first,Node *sec){
    Node* temp=(sec)->next;
    (sec)->next=*first;
    *first=sec;
    return(temp);
}

Node* Flip_Linked_List(Node* head){
    Node *next_node,*curr_node;
    curr_node=head;
    next_node=head->next;
    curr_node->next=NULL;
    while (next_node!=NULL){
    	next_node=switch_node(&curr_node,next_node);
    }
    return (curr_node);
}

Node* flip_rec_linked_list(Node* head,Node **prev){
    if (head->next==NULL){
        head->next=*prev;
        return(head);
    } else {
        Node * to_ret = flip_rec_linked_list(head->next,&head);
       	head->next=*prev;
        return(to_ret);
    }
}

//Q5 merge two sorted linked listes
Node* merge_two_lists(Node* first,Node *sec){
    if (first == NULL){
        return sec;
    }
    if (sec == NULL){
        return first;
    }
    
    Node *merged=NULL;
    if ((first->data) > (sec->data)){
        merged = first;
        merged->next =  merge_two_lists(first->next,sec);  
    } else {
        merged = sec;
        merged->next =  merge_two_lists(first,sec->next);  
    
    }
    return(merged);
}