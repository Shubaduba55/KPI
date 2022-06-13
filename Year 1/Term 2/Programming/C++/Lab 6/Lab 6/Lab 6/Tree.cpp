#pragma once
#include "Tree.h"

void Tree::set_root(Node* root) { this->root = root; }

Node* Tree::get_root() { return this->root; }


void Tree::tree_abcd(float a, float b, float c, float d) {
	assert(d != 0);
	Node* plus = create_node( Node(b), Node(c), '+');
	Node* mult = create_node(*plus, Node(a), '*');
	Node* div = create_node(*mult, Node(d), '/');
	root = new Node(*div);
}

Node* create_node(Node left, Node right, char sign) {
	float result, a = left.get_data(), b = right.get_data();
	if (sign == '+') { result = a + b; }
	else if (sign == '-') { result = a - b; }
	else if (sign == '*') { result = a * b; }
	else if (sign == '/') { result = a / b; }
	else result = 0;
	result = set_precision(result, 2);
	Node* node = new Node(result);
	node->set_left(left);
	node->set_right(right);
	return node;
}