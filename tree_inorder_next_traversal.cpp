#include <iostream>
using namespace std;

struct BinaryTreeNode{
    int data;
    Node *m_pParent;
    Node *m_pLeft;
    Node *m_pRight;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {
    if(pNode == NULL)
        return NULL;
    BinaryTreeNode* pNext = NULL;
	// if i have a right child
    if(pNode->m_pRight != NULL) {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != NULL)
            pRight = pRight->m_pLeft;
        pNext = pRight;
	// this is the end of the tree part, i need to return to the source.
    }else if(pNode->m_pParent != NULL) {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != NULL && pCurrent == pParent->m_pRight) {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }
    return pNext;
}

int main(){
    return 0;
}