struct Node {
	Node *left;
	Node *right;
	int data;
};


//takes sorted array and maked it a binary tree
Node * buildTree(int array[],int start,int end){
	if ((array == NULL) || (start > end))
		return NULL;
	Node * node;
	int mid = (start+(end-start)/2);
	node = new Node;
	node->data = array[mid];
	node->left = buildTree(array,start,mid-1);
	node->right =  buildTree(array,mid+1,end);
	return node;

}