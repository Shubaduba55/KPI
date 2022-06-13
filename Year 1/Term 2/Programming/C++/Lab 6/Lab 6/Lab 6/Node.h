#include <iostream>
#include <string>

using std::string;
using std::to_string;


class Node {
private:
	float data;
	Node *left, *right;
public:
	Node(float num = 0) : data(num), left(nullptr), right(nullptr) {}
	Node(const Node&);
	Node(Node&&);
	void set_left(const Node&);
	void set_right(const Node&);
	void set_left(const float);
	void set_right(const float);
	float get_data();
	Node* get_branch(bool);
	void print(int = 0);
	friend std::ostream& operator <<(std::ostream&, const Node&);
	friend Node* make_tree(float*, int, int);
};

Node* make_tree(float*, int, int);

