#include "Functions.h"

void get_abcd(int& a, int& b, int& c, int& d) {
	cout << "Enter 4 numbers(a, b, c, d): ";
	cin >> a;	cin >> b;	cin >> c;	cin >> d;
}

float set_precision(float num, int precision) {
	assert(precision < 9);
	int tmp = num / pow(10, -precision);
	return float(tmp/ pow(10, precision));
}

void preorder(Node* node) {
	if (node == nullptr) return;
	cout << node->get_data() << "  ";
	preorder(node->get_branch(0));
	preorder(node->get_branch(1));
}
void postorder(Node* node) {
	if (node == nullptr) return;
	postorder(node->get_branch(0));
	postorder(node->get_branch(1));
	cout << node->get_data() << "  ";
}
void inorder(Node* node) {
	if (node == nullptr) return;
	inorder(node->get_branch(0));
	cout << node->get_data() << "  ";
	inorder(node->get_branch(1));
}