#include "BST.h"

BST::Stack::Stack()
{
	topNode = nullptr;
}

BST::Stack::~Stack()
{
	while (topNode!=nullptr) pop();
	delete topNode;
}

void BST::Stack::push(Node* newElem)
{
	if (!isEmpty()) topNode = new StackNode(newElem, topNode);
	else topNode = new StackNode(newElem);
}

BST::Node* BST::Stack::pop()
{
	Node* temp = topNode->elem;
	topNode = topNode->next;
	return temp;
}

bool BST::Stack::isEmpty()
{
	if (topNode == nullptr) return true;
	else return false;
}

BST::Node* BST::Stack::top()
{
	return topNode->elem;
}
