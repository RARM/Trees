// trees.hpp -- Definitio of tree data models.
// Read trees.cpp for more information on classes and methods.
#ifndef _TREES_H_
#define _TREES_H_

#include <string>

namespace rarm_trees
{
	// Binary Tree
	template <typename T>
	class Binary_Tree
	{
	public:
		Binary_Tree(T data_val, Binary_Tree* left = nullptr, Binary_Tree* Right = nullptr);
		Binary_Tree(const Binary_Tree& source); // Deep copy.
		~Binary_Tree();

		// Traversal functions.
		std::string inorder();
		std::string preorder();
		std::string postorder();

		// AVOID USING THESE FUNCTIONS BELOW
		// WHEN WORKING WITH BST.
		// That could invalidate the BST.
		
		// Insert functions.
		void manual_ins_left(Binary_Tree* data);
		void manual_ins_right(Binary_Tree* data);

		// Delete functions.
		void manual_del_left();
		void manual_del_right();

		// Get current value.
		T get_value();
		Binary_Tree<T>* left_child();
		Binary_Tree<T>* right_child();

	protected:
		T data;
		Binary_Tree<T>* left;
		Binary_Tree<T>* right;
	};

	template <typename T>
	class BST : public Binary_Tree<T>
	{
	public:
		BST(T data);
		BST(const BST& source);
		~BST();

		// Functions
		BST* search();
		bool insert();
		bool del(); // delete
	};	
}

/* Creating template classes makes it difficult to
 * separate the header file of the implementation.
 * 
 * Read more about this issue here:
 * https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl
 * 
 * After finishinf this header, I will probably separate them
 * with the solution presented the in the link above.
*/

// ---------------------- BINARY TREE ----------------------
// General constructor for the Binary_Tree class.
template <typename T>
rarm_trees::Binary_Tree<T>::Binary_Tree(T data_val, Binary_Tree* left, Binary_Tree* right)
	: data { data_val }
{
	// Left tree.
	this->left = (left == nullptr) ? nullptr : new Binary_Tree(*left);

	// Right tree.
	this->right = (right == nullptr) ? nullptr : new Binary_Tree(*right);
}

// Copy constructor.
template <typename T>
rarm_trees::Binary_Tree<T>::Binary_Tree(const Binary_Tree& source)
	: data { source.data }
{
	// Left tree.
	this->left = (source.left == nullptr) ? nullptr : new Binary_Tree(*(source.left));

	// Right tree.
	this->right = (source.right == nullptr) ? nullptr : new Binary_Tree(*(source.right));
}

// Desctructor.
template <typename T>
rarm_trees::Binary_Tree<T>::~Binary_Tree()
{
	if (this->left != nullptr) delete this->left;
	if (this->right != nullptr) delete this->right;
	return;
}

// Manual insertions.
template <typename T>
void rarm_trees::Binary_Tree<T>::manual_ins_left(Binary_Tree* data)
{ this->left = data; return; }

template <typename T>
void rarm_trees::Binary_Tree<T>::manual_ins_right(Binary_Tree* data)
{ this->right = data; return; }

// Manual deletions.
// These functions will recursively delete a node and all its childrens.
// The recursion is done in the destructor.
template <typename T>
void rarm_trees::Binary_Tree<T>::manual_del_left()
{ delete this->left; return; }

template <typename T>
void rarm_trees::Binary_Tree<T>::manual_del_right()
{ delete this->right; return; }

// Traversal operations.

// inorder: returns the inorder traversal of the tree
// as a std::string.
template <typename T>
std::string rarm_trees::Binary_Tree<T>::inorder()
{
	// This function will produce a string with all the
	// values in order. The string could then be used
	// as an output.
	std::string output;

	// bool isString = std::is_same<T, std::string>::value

	if (this->left != nullptr) output += (*(this->left)).inorder();
	output += std::string(this->data) + " ";
	if (this->right != nullptr) output += (*(this->right)).inorder();

	return output;
}

// preorder: returns the preorder traversal of the tree
// as a std::string.
template <typename T>
std::string rarm_trees::Binary_Tree<T>::preorder()
{
	std::string output;

	output += std::string(this->data) + " ";
	if (this->left != nullptr) output += (*(this->left)).preorder();
	if (this->right != nullptr) output += (*(this->right)).preorder();

	return output;
}

// postorder: returns the postorder traversal of the tree
// as a std::string.
template <typename T>
std::string rarm_trees::Binary_Tree<T>::postorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).postorder();
	if (this->right != nullptr) output += (*(this->right)).postorder();
	output += std::string(this->data) += " ";

	return output;
}

// Getters.
template <typename T>
T rarm_trees::Binary_Tree<T>::get_value()
{ return this->data; }

template <typename T>
rarm_trees::Binary_Tree<T>* rarm_trees::Binary_Tree<T>::left_child()
{ return this->left; }

template <typename T>
rarm_trees::Binary_Tree<T>* rarm_trees::Binary_Tree<T>::right_child()
{ return this->right; }

#endif