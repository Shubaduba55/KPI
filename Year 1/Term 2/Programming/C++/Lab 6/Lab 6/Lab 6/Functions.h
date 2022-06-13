#pragma once
#include <iostream>
#include <cassert>
#include "Node.h"
using std::cout;
using std::cin;

void get_abcd(int&, int&, int&, int&);

float set_precision(float, int);

void preorder(Node*);
void postorder(Node*);
void inorder(Node*);