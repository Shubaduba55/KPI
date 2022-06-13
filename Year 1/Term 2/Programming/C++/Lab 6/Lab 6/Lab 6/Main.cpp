#include <iostream>
#include "Tree.h"
using std::cout;
using std::cin;


int main() {
	int a, b, c, d;
	Tree tmp;

	get_abcd(a, b, c, d);
	tmp.tree_abcd(a, b, c, d);

	Node* root = tmp.get_root();
	(*root).print();
	cout << "\n\nPreorder: "; preorder(root);
	cout << "\n\nPostorder: "; postorder(root);
	cout << "\n\nInorder: "; inorder(root);
	
	return 0;
}


