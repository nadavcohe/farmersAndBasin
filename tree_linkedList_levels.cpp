struct Node {
	Node *left;
	Node *right;
	int data;
};

//create vector of diffrent levels in the tree
typedef vector<vector < int > > list_type;
void levelList(Node *node,list_type &L,int level){
	if (node == NULL){
		return;
	}
	if (L.size()<level){
		vector < int > s;
		L.push_back(s);
	}
	(L[level-1]).push_back(node->data);
	levelList(node->right,L,level+1);
	levelList(node->left,L,level+1);
}