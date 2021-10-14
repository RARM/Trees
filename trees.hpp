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
		Binary_Tree(T data);
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

#endif