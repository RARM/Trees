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
		Binary_Tree(T data_val = NULL);
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

// General constructor for the Binary_Tree class.
template <typename T>
rarm_trees::Binary_Tree<T>::Binary_Tree(T data_val)
	: data { data_val }
{
	this->left = nullptr;
	this->right = nullptr;
}

// Copy constructor.
template <typename T>
rarm_trees::Binary_Tree<T>::Binary_Tree(const Binary_Tree& source)
	: Binary_Tree(source.data, *source.left, *source.right)
{}

// Desctructor.
template <typename T>
rarm_trees::Binary_Tree<T>::~Binary_Tree()
{
	return;
}

// Get value.
template <typename T>
T rarm_trees::Binary_Tree<T>::get_value()
{
	return this->data;
}

#endif