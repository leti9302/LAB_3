#include "BST.h"
#include <iostream>

using namespace std;

int main() {
	BST* bst = new BST();
	bst->insert(8);
	bst->insert(3);
	bst->insert(1);
	bst->insert(10);
	bst->insert(14);
	bst->insert(13);
	bst->insert(7);
	Iterator* bst_iterator = bst->create_bft_iterator();
	while (bst_iterator->has_next())
		cout << bst_iterator->next() << ' ';
}