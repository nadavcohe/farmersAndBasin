using namespace std;
struct Node
{
	int data;
	Node *next;
};
/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

bool check_next(Node *node,int pat){
	if (node==NULL){
		return false;
	}
	if (node->next==NULL){
		return false;
	}
	if (node->next->data==pat){
		Node *temp = node->next;
		node->next = temp->next;
		delete temp;
		return true;
	}
	return false;

}

void findDup(Node *node,int pat){
	if (node==NULL){
		return;
	}
	check_next(node,pat);

	findDup(node->next,pat);
}

Node* RemoveDuplicates(Node *head)
{
    Node *temp = head;
    int ptr;
	while (head!=NULL){
        ptr=head->data;
		while (check_next(head,ptr)){};
		findDup(head->next,ptr);
		head=head->next;
	}
    return temp;
    
}