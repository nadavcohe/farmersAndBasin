#include <iostream>
using namespace std;

struct BinaryTreeNode{
    int data;
    Node *m_pParent;
    Node *m_pLeft;
    Node *m_pRight;
};

// inorder travers
void travers_inorder(BinaryTreeNode *node){
    if (node == NULL)
        return;
    travers_inorder(node->m_pLeft);
    cout << data << "\t";
    travers_inorder(node->m_pRight);
}

//using 

int main(){
    return 0;
}