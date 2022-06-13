#pragma once
#include <iostream>
#include <cassert>
#include "Functions.h"
class Tree {
	friend Node;
private:
	Node* root;
public:
	Tree() :root(NULL) {}
	Tree(Node* root) : root(root) {}
	~Tree() { delete[] root; }
	
	void set_root(Node* root);
	Node* get_root();
	void tree_abcd(float, float, float, float);
};

Node* create_node(Node, Node, char);