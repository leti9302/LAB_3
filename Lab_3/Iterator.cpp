#include "BST.h"
#include <stdexcept>

Iterator* BST::create_dft_iterator()
{
	return new dftIterator(root);
}

BST::dftIterator::dftIterator(Node* start)
{
	stack = new Stack();
	stack->push(start);
}

bool BST::dftIterator::has_next()
{
	return !stack->isEmpty();
}

int BST::dftIterator::next()
{
	if (!has_next()) throw std::out_of_range("No more elements!");
	Node* current = stack->pop();
	if (current->right != nullptr) stack->push(current->right);
	if (current->left != nullptr) stack->push(current->left);
	return current->data;
}

Iterator* BST::create_bft_iterator()
{
	return new bftIterator(root);
}

BST::bftIterator::bftIterator(Node* start)
{
	queue = new Queue();
	queue->enqueue(start);
}

bool BST::bftIterator::has_next()
{
	return !queue->isEmpty();
}

int BST::bftIterator::next()
{
	if (!has_next()) throw std::out_of_range("No more elements!");
	Node* current = queue->dequeue();
	if (current->left != nullptr) queue->enqueue(current->left);
	if (current->right != nullptr) queue->enqueue(current->right);
	return current->data;
}