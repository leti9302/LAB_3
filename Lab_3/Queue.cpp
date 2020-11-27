#include "BST.h"

BST::Queue::Queue()
{
	first = nullptr;
	last = nullptr;
}

BST::Queue::~Queue()
{
	while (first != nullptr) dequeue();
	delete first;
}

void BST::Queue::enqueue(Node* newElem)
{
	if (!isEmpty())
	{
		last->next = new QueueNode(newElem);
		last = last->next;
	}
	else {
		first = new QueueNode(newElem);
		last = first;
	}
}

BST::Node* BST::Queue::dequeue()
{
	Node* temp = first->elem;
	first = first->next;
	return temp;
}

bool BST::Queue::isEmpty()
{
	if (first == nullptr) return true;
	else return false;
}

BST::Node* BST::Queue::peek()
{
	return first->elem;
}