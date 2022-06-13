#pragma once
#include "Node.h"

Node::Node(const Node& other) {
	data = other.data;
	left = other.left;
	right = other.right;
}
Node::Node(Node&& other) {
	data = other.data;
	left = other.left;
	other.left = nullptr;
	right = other.right;
	other.right = nullptr;
}

void Node::set_left(const Node& branch) {	left = new Node(branch); }
void Node::set_right(const Node& branch) { right = new Node(branch); }
void Node::set_left(const float num) { left = new Node(num); }
void Node::set_right(const float num) { right = new Node(num); }
float Node::get_data() { return data; }

Node* make_tree(float* members, int start, int num) {
	if (num == 0) return NULL;
	Node* node = new Node(members[start]);
	int num_left = num / 2, num_right = num - num_left - 1;
	node->left = make_tree(members, start + 1, num_left);
	node->right = make_tree(members, start + 1 + num_left, num_right);
	return node;
}

std::ostream& operator <<(std::ostream& out, const Node& node){
	string left, right;
	(node.left == nullptr) ? left = "NULL" : left = to_string(node.left->data);
	(node.right == nullptr) ? right = "NULL" : right = to_string(node.right->data);
	out << "Node value: " << node.data << "\nLeft value: " + left + "\t Right value: " + right;
	return out;
}

Node* Node::get_branch(bool is_right) {
	if (is_right) { return this->right; }
	else { return this->left; }
}


void Node::print(int tabs){
	if (!this) return;
	tabs += 5;

	right->print(tabs);

	for (int i = 0; i < tabs; i++) std::cout << " ";
	std::cout << this->data << std::endl;
	
	left->print(tabs);
	return;
}