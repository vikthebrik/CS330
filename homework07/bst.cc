#include "bst.h"

// ---------------------------------------
// Node class
// Default constructor
Node::Node() {
// TODO: Implement this
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}
// Constructor
Node::Node(int in) {
// TODO: Implement this
	key = in;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}
// Destructor
Node::~Node() {
// TODO: Implement this
	
}

// Add parent 
void Node::add_parent(Node* in) {
// TODO: Implement this
	parent = in;
}
// Add to left of current node
void Node::add_left(Node* in) {
// TODO: Implement this
	left = in;
}
// Add to right of current node
void Node::add_right(Node* in) {
// TODO: Implement this
	right = in;
}

// Get key
int Node::get_key()
{
// TODO: Implement this
	return key;
}
// Get parent node
Node* Node::get_parent()
{
// TODO: Implement this
	return parent;
}
// Get left node
Node* Node::get_left()
{
// TODO: Implement this
	return left;
}
// Get right node
Node* Node::get_right()
{
// TODO: Implement this
	return right;
}
// Print the key to ostream to
// Do not change this
void Node::print_info(ostream& to)
{
    to << key << endl;
}
// ---------------------------------------


// ---------------------------------------
// BST class
// Walk the subtree from the given node
void BST::inorder_walk(Node* in, ostream& to)
{
// TODO: Implement this
	//Tree traversal - recursive
	if (in != nullptr) {
		
		inorder_walk(in->get_left(), to);
		in->print_info(to);
		inorder_walk(in->get_right(), to);
	}
}
// Constructor
BST::BST()
{
// TODO: Implement this
	root = nullptr;
}
// Destructor
BST::~BST()
{
// TODO: Implement this
	while(root != nullptr)
	{
		delete_node(root);
	}
}
// Insert a node to the subtree
void BST::insert_node(Node* in)
{
// TODO: Implement this
	Node *y = root;
	Node *x = root;
//Bst traversal
	while(x != nullptr)
	{
		y = x;
		if(in->get_key() < x ->get_key())
		{
			x = x->get_left();
		}
		else
		{
			x = x->get_right();
		}

	}
//node insertion
	in->add_parent(y);
	if(y == nullptr)
	{
		root = in;
	}
	else if (in->get_key() < y->get_key())
	{
		y->add_left(in);

	}
	else
	{
		y->add_right(in);
	}
}
// Delete a node to the subtree
void BST::delete_node(Node* out)
{
// TODO: Implement this
// Check if node to delete has no left/right child
	if (out->get_left() == nullptr) 
	{
		transplant(out, out->get_right());
	}
	
	else if (out->get_right() == nullptr) 
	{
		transplant(out, out->get_left());
	}
//running if node has 2 children
	else 
	{
		Node *y = get_succ(out);
		
		if (y->get_parent() != out) 
		{
			transplant(y, y->get_right());
			
			y->add_right(out->get_right());
			y->get_right()->add_parent(y);
		}
		transplant(out, y);
		
		y->add_left(out->get_left());
		y->get_left()->add_parent(y);
	}
	delete out;
}
// minimum key in the BST
Node* BST::tree_min()
{
// TODO: Implement this
	Node *min = root;
	while (min->get_left() != nullptr) 
	{
		min = min->get_left();
	}
	return min;
}
// maximum key in the BST
Node* BST::tree_max()
{
// TODO: Implement this
	Node *max = root;
	while (max->get_right() != nullptr) 
	{
		max = max->get_right();
	}
	return max;
}
// Get the minimum node from the subtree of given node
Node* BST::get_min(Node* in)
{
// TODO: Implement this
	while (in->get_left() != nullptr) 
	{
		in = in->get_left();
	}
	return in;
}
// Get the maximum node from the subtree of given node
Node* BST::get_max(Node* in)
{
// TODO: Implement this
	while (in->get_right() != nullptr) {
		in = in->get_right();
	}
	return in;
}
// Get successor of the given node
Node* BST::get_succ(Node* in)
{
// TODO: Implement this
	//checking in right subtree
	if (in->get_right() != nullptr) {
		return get_min(in->get_right());
	}
	//Go up right tree for min
	Node *y = in->get_parent();
	while (y != nullptr and in == y->get_right()) {
		in = y;
		y = y->get_parent();
	}
	return y;
}
// Get predecessor of the given node
Node* BST::get_pred(Node* in)
{
// TODO: Implement this

	//If in left subtree
	if (in->get_left() != nullptr) {
		return get_max(in->get_left());
	}

	// Ot
	Node *y = in->get_parent();
	while (y != nullptr and in == y->get_left()) {
		in = y;
		y = y->get_parent();
	}
	return y;
}
// Walk the BST from min to max
void BST::walk(ostream& to)
{
// TODO: Implement this
	inorder_walk(root, to);
}
// Search the tree for a given key
Node* BST::tree_search(int search_key)
{
// TODO: Implement this
	Node *x = root;
	while (x != nullptr and search_key != x->get_key()) {
		if (search_key < x->get_key()) {
			x = x->get_left();
		}
		else {
			x = x->get_right();
		}
	}
	return x;
}

void BST::transplant(Node *u, Node *v) {

	if (u->get_parent() == nullptr) {
		root = v;
	}
	else if (u == u->get_parent()->get_left()) {
		u->get_parent()->add_left(v);
	}

	else {
		u->get_parent()->add_right(v);
	}

	if (v != nullptr) {
		v->add_parent(u->get_parent());
	}
}


// ---------------------------------------
