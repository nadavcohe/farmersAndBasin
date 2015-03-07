
// check to see if a tree is balanced
int findBalanced(Node *node){
	if (node == NULL)
		return 0;
	int left = findBalanced(node->left);
	if (left == -1)
		return -1;
	int right = findBalanced(node->right);
	if (right == -1)
		return -1;
	if (abs(right-left)) > 1){
		return -1;
	} else {
		return max(right,left)+1;
	}
}