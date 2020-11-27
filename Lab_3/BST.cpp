#include"BST.h"

BST::BST()
{
	root = nullptr;
}

BST::~BST()
{
	while (root != nullptr)
		remove(root->data);
	delete root;
}

bool BST::contains(int key)
{
	Node* current = root;
	while(current != nullptr)
	{
		if (current->data == key)
			return true;
		else if (current->data > key)
			current = current->left;
		else current = current->right;
	}
	return false;
}

void BST::insert(int key)
{
	if (root == nullptr) root = new Node(key);
	else {
		Node* current = root;
		bool to_right = false;
		while (1)
		{
			if (current->data >= key && current->left != nullptr)
				current = current->left;
			else if (current->data >= key && current->left == nullptr)
				break;
			else if (current->data < key && current->right != nullptr)
				current = current->right;
			else {
				to_right = true;
				break;
			}
		}
		if (to_right == false) current->left = new Node(key, nullptr, nullptr, current);
		else current->right = new Node(key, nullptr, nullptr, current);
	}
}

void BST::remove(int key)
{
	if (root == nullptr) throw "Tree is empty!";
	else if (root->left == nullptr && root->right == nullptr && root->data == key)
	{
		root = nullptr;
		return;
	}
	else if (root->left == nullptr && root->right == nullptr && root->data != key)
	{
		throw "There is no such element!:";
	}
	else {
		Node* current = root;
		Node* current_child;
		while (current != nullptr)
		{
			if (current->data == key)
			{
				if (current->left == nullptr && current->right == nullptr)
				{
					if ((current->parent)->left == current) (current->parent)->left = nullptr;
					else (current->parent)->right = nullptr;
					delete current;
				}
				else if (current->left != nullptr && current->right == nullptr)
				{
					current_child = current->left;
					current->data = current_child->data;
					current->left = current_child->left;
					current->right = current_child->right;
					if (current->left != nullptr)
						current->left->parent = current;
					if (current->right != nullptr)
						current->right->parent = current;
					delete current_child;
				}
				else if (current->left == nullptr && current->right != nullptr)
				{
					current_child = current->right;
					current->data = current_child->data;
					current->left = current_child->left;
					current->right = current_child->right;
					if (current->left != nullptr) current->left->parent = current;
					if (current->right != nullptr) current->right->parent = current;
					delete current_child;
				}
				else {
					current_child = current->right;
					if (current_child->left == nullptr)
					{
						current->right = current_child->right;
						if(current_child->right != nullptr) (current_child->right)->parent = current;
					}
					else
					{
						while (current_child->left != nullptr && current_child != nullptr) current_child = current_child->left;
						(current_child->parent)->left = current_child->right;
						if (current_child->right != nullptr) current_child->right->parent = current_child->parent;
					}
					current->data = current_child->data;
					delete current_child;
				}
				return;
			}
			else if (current->data > key)
				current = current->left;
			else current = current->right;
		}
		throw "There is no such element!:";
	}
}