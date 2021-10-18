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
	class BST
	{
	public:
		BST(T data_val);
		BST(const BST& source);
		~BST();

		T get_value();

		// Traversal functions.
		std::string inorder();
		std::string preorder();
		std::string postorder();

		// Functions
		BST* search(T search_value);
		BST* insert(T new_val);
		// bool del(T val_to_del); // delete node

	protected:
		T data;
		BST<T>* left;
		BST<T>* right;
	};	
}

#endif