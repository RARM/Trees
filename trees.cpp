// trees.cpp -- Implementation of the rarm_trees library.
#include "trees.hpp"

// ---------------------- BINARY TREE ----------------------
// General constructor for the Binary_Tree class.
template <typename T>
rarm_trees::Binary_Tree<T>::Binary_Tree(T data_val, Binary_Tree* left, Binary_Tree* right)
	: data{ data_val }
{
	// Left tree.
	this->left = (left == nullptr) ? nullptr : new Binary_Tree(*left);

	// Right tree.
	this->right = (right == nullptr) ? nullptr : new Binary_Tree(*right);
}

// Copy constructor.
template <typename T>
rarm_trees::Binary_Tree<T>::Binary_Tree(const Binary_Tree& source)
	: data{ source.data }
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
{
	this->left = data; return;
}

template <typename T>
void rarm_trees::Binary_Tree<T>::manual_ins_right(Binary_Tree* data)
{
	this->right = data; return;
}

// Manual deletions.
// These functions will recursively delete a node and all its childrens.
// The recursion is done in the destructor.

template <typename T>
void rarm_trees::Binary_Tree<T>::manual_del_left()
{
	delete this->left; return;
}

template <typename T>
void rarm_trees::Binary_Tree<T>::manual_del_right()
{
	delete this->right; return;
}

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

	if (this->left != nullptr) output += (*(this->left)).inorder();
	output += std::to_string(this->data) + " ";
	if (this->right != nullptr) output += (*(this->right)).inorder();

	return output;
}

// Read more about specialized templates here:
// https://en.cppreference.com/w/cpp/language/template_specialization

// This is an explicit class specialization.
// It works specifically for std::string.
// It behaves as the normal template.
template<>
std::string rarm_trees::Binary_Tree<std::string>::inorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).inorder();
	output += this->data + " ";
	if (this->right != nullptr) output += (*(this->right)).inorder();

	return output;
}

// preorder: returns the preorder traversal of the tree
// as a std::string.
template <typename T>
std::string rarm_trees::Binary_Tree<T>::preorder()
{
	std::string output;

	output += std::to_string(this->data) + " ";
	if (this->left != nullptr) output += (*(this->left)).preorder();
	if (this->right != nullptr) output += (*(this->right)).preorder();

	return output;
}

// preorder specialized class template.
template <>
std::string rarm_trees::Binary_Tree<std::string>::preorder()
{
	std::string output;

	output += this->data + " ";
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
	output += std::to_string(this->data) += " ";

	return output;
}

// postorder specialized class template.
template <>
std::string rarm_trees::Binary_Tree<std::string>::postorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).postorder();
	if (this->right != nullptr) output += (*(this->right)).postorder();
	output += this->data += " ";

	return output;
}

// Getters.

template <typename T>
T rarm_trees::Binary_Tree<T>::get_value()
{
	return this->data;
}

template <typename T>
rarm_trees::Binary_Tree<T>* rarm_trees::Binary_Tree<T>::left_child()
{
	return this->left;
}

template <typename T>
rarm_trees::Binary_Tree<T>* rarm_trees::Binary_Tree<T>::right_child()
{
	return this->right;
}

// ---------------------- BINARY SEARCH TREE ----------------------

// BST Constructor
// Creates a BST node with data of type T.
// All its children must be the same data type.
template <typename T>
rarm_trees::BST<T>::BST(T data_val)
{
	this->data = data_val;
	this->left = nullptr;
	this->right = nullptr;
}

// BST Copy Constructor
// It recursevily rebuilds the tree allocating new memory for the copy.
template <typename T>
rarm_trees::BST<T>::BST(const rarm_trees::BST<T>& source)
{
	this->data = source.data;

	// Recursively rebuild the tree.
	this->left = (source.left == nullptr) ? nullptr : new rarm_trees::BST<T>(*(source.left));
	this->right = (source.right == nullptr) ? nullptr : new rarm_trees::BST<T>(*(source.right));

	return;
}

// BST Destructor
// It recursively frees the memory of the nodes of the children of the tree.
template <typename T>
rarm_trees::BST<T>::~BST()
{
	if (this->left != nullptr) delete this->left;
	if (this->right != nullptr) delete this->right;

	return;
}

template <typename T>
T rarm_trees::BST<T>::get_value()
{ return this->data; }

// Traversal operations.

// inorder: returns the inorder traversal of the tree
// as a std::string.
template <typename T>
std::string rarm_trees::BST<T>::inorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).inorder();
	output += std::to_string(this->data) + " ";
	if (this->right != nullptr) output += (*(this->right)).inorder();

	return output;
}

// BST specialized inorder.
template<>
std::string rarm_trees::BST<std::string>::inorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).inorder();
	output += this->data + " ";
	if (this->right != nullptr) output += (*(this->right)).inorder();

	return output;
}

// preorder: returns the preorder traversal of the tree
// as a std::string.
template <typename T>
std::string rarm_trees::BST<T>::preorder()
{
	std::string output;

	output += std::to_string(this->data) + " ";
	if (this->left != nullptr) output += (*(this->left)).preorder();
	if (this->right != nullptr) output += (*(this->right)).preorder();

	return output;
}

// BST specialized preorder.
template <>
std::string rarm_trees::BST<std::string>::preorder()
{
	std::string output;

	output += this->data + " ";
	if (this->left != nullptr) output += (*(this->left)).preorder();
	if (this->right != nullptr) output += (*(this->right)).preorder();

	return output;
}

// postorder: returns the postorder traversal of the tree
// as a std::string.
template <typename T>
std::string rarm_trees::BST<T>::postorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).postorder();
	if (this->right != nullptr) output += (*(this->right)).postorder();
	output += std::to_string(this->data) += " ";

	return output;
}

// BST specialized postorder.
template <>
std::string rarm_trees::BST<std::string>::postorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).postorder();
	if (this->right != nullptr) output += (*(this->right)).postorder();
	output += this->data += " ";

	return output;
}

// Search, insert, delete.

// Search
// Given a value, the function will return the pointer to that address.
template <typename T>
rarm_trees::BST<T>* rarm_trees::BST<T>::search(T search_value)
{
	if (this->data == search_value) return this;
	else if (search_value < this->data && this->left != nullptr) return (*(this->left)).search(search_value);
	else if (search_value > this->data && this->right != nullptr) return (*(this->right)).search(search_value);
	else return nullptr;
}

// Insert
// It adds the given value on the respective index to keep the valid search tree.
// If the value already exists, it behaves like the search method.
template <typename T>
rarm_trees::BST<T>* rarm_trees::BST<T>::insert(T new_val)
{
	if (new_val == this->data) return this;
	else if (new_val < this->data)
		if (this->left != nullptr) return (*(this->left)).insert(new_val);
		else return (this->left = new rarm_trees::BST<T>(new_val));
	else if (new_val > this->data)
		if (this->right != nullptr) return (*(this->right)).insert(new_val);
		else return (this->right = new rarm_trees::BST<T>(new_val));
}


/* Creating template classes makes it difficult to
 * separate the header file of the implementation.
 *
 * Read more about this issue here:
 * https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl
 *
 * I am adding some definitions below to fix linking error.
*/

template rarm_trees::Binary_Tree<char>;
template rarm_trees::Binary_Tree<std::string>;
template rarm_trees::Binary_Tree<int>;
template rarm_trees::Binary_Tree<long long>;

template rarm_trees::BST<char>;
template rarm_trees::BST<std::string>;
template rarm_trees::BST<int>;
template rarm_trees::BST<long long>;
