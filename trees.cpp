// trees.cpp -- Implementation of the rarm_trees library.
#include "trees.hpp"

// -------------------------------- BINARY TREE --------------------------------

// Constructor for the Binary_Tree class.
template <typename T>
rarm_trees::Binary_Tree<T>::Binary_Tree(T data_val, Binary_Tree* left, Binary_Tree* right)
	: data{ data_val }
{
	this->left = (left == nullptr) ? nullptr : new Binary_Tree(*left); // Left tree.
	this->right = (right == nullptr) ? nullptr : new Binary_Tree(*right); // Right tree.
	return;
}

// Deep copy constructor for the Binary_Tree class.
template <typename T>
rarm_trees::Binary_Tree<T>::Binary_Tree(const Binary_Tree& source)
	: data{ source.data }
{
	this->left = (source.left == nullptr) ? nullptr : new Binary_Tree(*(source.left)); // Left tree.
	this->right = (source.right == nullptr) ? nullptr : new Binary_Tree(*(source.right)); // Right tree.
	return;
}

// Destructor for the Binary_Tree class.
template <typename T>
rarm_trees::Binary_Tree<T>::~Binary_Tree()
{
	// Recursively delete children and set left and right to nullptr.

	if (this->left != nullptr)
	{
		delete this->left;
		this->left = nullptr;
	}

	if (this->right != nullptr)
	{
		delete this->right;
		this->right = nullptr;
	}

	return;
}

// ----------------------------- INSERT FUNCTIONS ------------------------------

// Add the pointer of another Binary_Tree as the left child of the node.
template <typename T>
void rarm_trees::Binary_Tree<T>::ins_left(Binary_Tree* data)
{
	this->left = data; return;
}

// Add the pointer of another Binary_Tree as the right child of the node.
template <typename T>
void rarm_trees::Binary_Tree<T>::ins_right(Binary_Tree* data)
{
	this->right = data; return;
}

// ----------------------------- DELETE FUNCTIONS ------------------------------

// Deallocates the node on the left and all its children. Then, it sets the left
// child to nullptr.
template <typename T>
void rarm_trees::Binary_Tree<T>::del_left()
{
	delete this->left;
	this->left = nullptr;
	return;
}

// Deallocates the node on the right and all its children. Then, it sets the
// right child to nullptr.
template <typename T>
void rarm_trees::Binary_Tree<T>::del_right()
{
	delete this->right;
	this->right = nullptr;
	return;
}

// --------------------------- TRAVERSAL OPERATIONS ----------------------------

// Returns std::string containing the inorder traversal of the tree.
template <typename T>
std::string rarm_trees::Binary_Tree<T>::inorder()
{
	// This function will produce a string with all the values inorder. The
	// string could then be used for output.
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).inorder();
	output += std::to_string(this->data) + " ";
	if (this->right != nullptr) output += (*(this->right)).inorder();

	return output;
}

// Read more about specialized templates here:
// https://en.cppreference.com/w/cpp/language/template_specialization

// Converting the data to string is not necessary. It will throw a compilation
// error. Therefore, a specialized implementation is useful in this scenario.

// Explicit class specialization for std::string of inorder traversal operation.
template<>
std::string rarm_trees::Binary_Tree<std::string>::inorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).inorder();
	output += this->data + " ";
	if (this->right != nullptr) output += (*(this->right)).inorder();

	return output;
}

// Returns std::string containing the preorder traversal of the tree.
template <typename T>
std::string rarm_trees::Binary_Tree<T>::preorder()
{
	std::string output;

	output += std::to_string(this->data) + " ";
	if (this->left != nullptr) output += (*(this->left)).preorder();
	if (this->right != nullptr) output += (*(this->right)).preorder();

	return output;
}

// Explicit class specialization for std::string of preorder traversal
// operation.
template <>
std::string rarm_trees::Binary_Tree<std::string>::preorder()
{
	std::string output;

	output += this->data + " ";
	if (this->left != nullptr) output += (*(this->left)).preorder();
	if (this->right != nullptr) output += (*(this->right)).preorder();

	return output;
}

// Returns std::string containing the postorder traversal of the tree.
template <typename T>
std::string rarm_trees::Binary_Tree<T>::postorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).postorder();
	if (this->right != nullptr) output += (*(this->right)).postorder();
	output += std::to_string(this->data) + " ";

	return output;
}

// Explicit class specialization for std::string of postorder traversal
// operation.
template <>
std::string rarm_trees::Binary_Tree<std::string>::postorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).postorder();
	if (this->right != nullptr) output += (*(this->right)).postorder();
	output += this->data + " ";

	return output;
}

// ---------------------------------- GETTERS ----------------------------------

// Returns the value of the current node.
template <typename T>
T rarm_trees::Binary_Tree<T>::get_value()
{
	return this->data;
}

// Returns pointer to the left child of the current node.
template <typename T>
rarm_trees::Binary_Tree<T>* rarm_trees::Binary_Tree<T>::left_child()
{
	return this->left;
}

// Returns pointer to the right child of the current node.
template <typename T>
rarm_trees::Binary_Tree<T>* rarm_trees::Binary_Tree<T>::right_child()
{
	return this->right;
}



// ---------------------------- BINARY SEARCH TREE -----------------------------

// Constructor for the Binary Search Tree (BST).
template <typename T>
rarm_trees::BST<T>::BST(T data_val)
{
	this->data = data_val;
	this->left = nullptr;
	this->right = nullptr;
}

// Deep copy constructor for the Binary Search Tree (BST).
template <typename T>
rarm_trees::BST<T>::BST(const rarm_trees::BST<T>& source)
{
	this->data = source.data;

	// Recursively rebuild the tree.
	this->left = (source.left == nullptr) ? nullptr : new rarm_trees::BST<T>(*source.left);
	this->right = (source.right == nullptr) ? nullptr : new rarm_trees::BST<T>(*source.right);

	return;
}

// Destructor for the Binary Search Tree (BST).
template <typename T>
rarm_trees::BST<T>::~BST()
{
	// Recursively delete children and set left and right to nullptr.

	if (this->left != nullptr)
	{
		delete this->left;
		this->left = nullptr;
	}

	if (this->right != nullptr)
	{
		delete this->right;
		this->right = nullptr;
	}

	return;
}

// ---------------------------------- GETTERS ----------------------------------

// Retuns the data of this node.
template <typename T>
T rarm_trees::BST<T>::get_value()
{ return this->data; }

// Returns true if both children are nullptr; return true otherwise.
template <typename T>
bool rarm_trees::BST<T>::is_leaf()
{ return (this->left == nullptr && this->right == nullptr) ? true : false; }

// --------------------------- TRAVERSAL OPERATIONS ----------------------------

// Returns std::string containing the inorder traversal of the tree.
template <typename T>
std::string rarm_trees::BST<T>::inorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).inorder();
	output += std::to_string(this->data) + " ";
	if (this->right != nullptr) output += (*(this->right)).inorder();

	return output;
}

// Explicit class specialization for std::string of inorder traversal opeartion.
template<>
std::string rarm_trees::BST<std::string>::inorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).inorder();
	output += this->data + " ";
	if (this->right != nullptr) output += (*(this->right)).inorder();

	return output;
}

// Returns std::string containing the preorder traversal of the tree.
template <typename T>
std::string rarm_trees::BST<T>::preorder()
{
	std::string output;

	output += std::to_string(this->data) + " ";
	if (this->left != nullptr) output += (*(this->left)).preorder();
	if (this->right != nullptr) output += (*(this->right)).preorder();

	return output;
}

// Explicit class specialization for std::string of preorder traversal
// opeartion.
template <>
std::string rarm_trees::BST<std::string>::preorder()
{
	std::string output;

	output += this->data + " ";
	if (this->left != nullptr) output += (*(this->left)).preorder();
	if (this->right != nullptr) output += (*(this->right)).preorder();

	return output;
}

// Returns std::string containing the postorder traversal of the tree.
template <typename T>
std::string rarm_trees::BST<T>::postorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).postorder();
	if (this->right != nullptr) output += (*(this->right)).postorder();
	output += std::to_string(this->data) + " ";

	return output;
}

// Explicit class specialization for std::string of postorder traversal
// operation.
template <>
std::string rarm_trees::BST<std::string>::postorder()
{
	std::string output;

	if (this->left != nullptr) output += (*(this->left)).postorder();
	if (this->right != nullptr) output += (*(this->right)).postorder();
	output += this->data + " ";

	return output;
}

// Helper method for the delete operation. It returns the inorder successor of
// of the current node. It returns a pointer to itself if no successor is
// available.
template <typename T>
rarm_trees::BST<T>* rarm_trees::BST<T>::inorder_successor()
{
	if (this->right == nullptr) return this;
	else
	{
		rarm_trees::BST<T>* controller = this->right;
		while (controller->left != nullptr)
			controller = controller->left;
		return controller;
	}
}

//----------------------------- BST OPEARTIONS ---------------------------------

// Returns pointer to node that cointains the given search_value (key).
template <typename T>
rarm_trees::BST<T>* rarm_trees::BST<T>::search(T search_value)
{
	if (this->data == search_value) return this;
	else if (search_value < this->data && this->left != nullptr) return (*(this->left)).search(search_value);
	else if (search_value > this->data && this->right != nullptr) return (*(this->right)).search(search_value);
	else return nullptr;
}

// Inserts a new node with the given value to the BST. It maintains the validity
// of the Binary Search Tree. If the value already exists on the tree, it will
// behave like the search operation.
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


// It deletes the node containing the given val_to_del (key). Return value is
// used for recursion.
template <typename T>
rarm_trees::BST<T>* rarm_trees::BST<T>::del(T val_to_del)
{
	// Three cases:
	// 1. Node to be deleted is a leaf.
	// 2. Node to be deleted has a child.
	// 3. Node to be deleted has two children.

	// Working with recursive functions.

	if (this == nullptr) return this;
	else if (val_to_del < this->data)
	{
		this->left = (*this->left).del(val_to_del);
		return this;
	}
	else if (val_to_del > this->data)
	{
		this->right = (*this->right).del(val_to_del);
		return this;
	}

	// If this is the node to be deleted...
	else
	{
		// Case 1: this is a leaf.
		if (this->is_leaf())
		{
			delete this;
			return nullptr;
		}

		// Case 2: has one child.
		else if (this->left == nullptr) // Child is on the right.
		{
			rarm_trees::BST<T>* temp = new rarm_trees::BST<T>((*this->right));
			delete this->right;
			return temp;
		}
		else if (this->right == nullptr) // Child is on the left.
		{
			rarm_trees::BST<T>* temp = new rarm_trees::BST<T>((*this->left));
			delete this->left;
			return temp;
		}

		// Case 3: node has two children.
		else
		{
			// Transfer data of the inoders successor.
			T temp_data = (*this->inorder_successor()).data;
			this->data = temp_data;

			// Delete inorder successor.
			this->right = (*this->right).del(data);

			return this;
		}
	}
}

/* Creating template classes makes it difficult to separate the header file of
 * the implementation.
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
