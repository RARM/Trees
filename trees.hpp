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
		// Insert functions.
		void manual_ins_left(Binary_Tree* data);
		void manual_ins_right(Binary_Tree* data);

		// Delete functions.
		void manual_del_left();
		void manual_del_right();

		// Get current value.
		T get_value();

	protected:
		T data;
		Binary_Tree* left;
		Binary_Tree* right;
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

// Get value.
template <typename T>
T rarm_trees::Binary_Tree<T>::get_value()
{
	return this->data;
}

#endif