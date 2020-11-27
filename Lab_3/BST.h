#pragma once
#include"Iterator.h"

class BST//BST - Binary search tree
{
private:
	class Node
	{
	public:
		Node(int data, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) {
			this->data = data;
			this->left = left;
			this->right = right;
			this->parent = parent;
		};
		~Node() {};

		int data;
		Node* left;
		Node* right;
		Node* parent;
	};

	Node* root;
public:
	BST();
	~BST();

	bool contains(int);
	void insert(int);
	void remove(int);

	class Queue
	{
	private:
		class QueueNode//Class for the QueueNode of the Queue
		{
		public:
			QueueNode(Node* elem, QueueNode* next = nullptr)
			{
				this->elem = elem;
				this->next = next;
			};
			~QueueNode() {};

			Node* elem;
			QueueNode* next;
		};
		QueueNode* first; //Top element of the Queue
		QueueNode* last;
	public:
		Queue();
		~Queue();

		void enqueue(Node*);
		Node* dequeue();
		bool isEmpty();
		Node* peek();
	};

	class Stack
	{
	private:
		class StackNode	//Class for the StackNode of the Stack
		{
		public:
			StackNode(Node* elem, StackNode* next = nullptr)
			{
				this->elem = elem;
				this->next = next;
			};
			~StackNode() {};

			Node* elem;
			StackNode* next;
		};
		StackNode* topNode; //Top element of the Stack
	public:
		Stack();
		~Stack();

		void push(Node*);
		Node* pop();
		bool isEmpty();
		Node* top();
	};

	Iterator * create_dft_iterator();
	class dftIterator : public Iterator {
	public:
		dftIterator(Node* start);
		bool has_next() override;
		int next() override;
	private:
		Stack* stack;
	};

	Iterator* create_bft_iterator();
	class bftIterator : public Iterator {
	public:
		bftIterator(Node* start);
		bool has_next() override;
		int next() override;
	private:
		Queue* queue;
	};
};