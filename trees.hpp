// trees.hpp -- Definitio of tree data models.
// Read trees.cpp for more information on classes and methods.
#ifndef _TREES_H_
#define _TREES_H_

#include <string>
#include <vector>

namespace rarm_trees
{
	// ------------------------------ BINARY TREE ------------------------------

	// Binary Tree with some trivial opeartion and traversal methods.
	template <typename T>
	class Binary_Tree
	{
	public:
		// --------------------------- CONSTRUCTORS ----------------------------

		// Binary Tree constructor.
		Binary_Tree(T data_val, Binary_Tree* left = nullptr, Binary_Tree* Right = nullptr);

		// Binary Tree deep copy constructor.
		Binary_Tree(const Binary_Tree& source);

		// Binary Tree destructor.
		~Binary_Tree();



		// ----------------------- TRAVERSAL OPERATIONS ------------------------

		// Traversal inorder operation that returns a std::string.
		std::string inorder();

		// Traversal preorder operation that returns a std::string.
		std::string preorder();

		// Traversal postorder operation that returns a std::string.
		std::string postorder();



		// ------------------------- INSERT FUNCTIONS --------------------------

		// Insert a Binary Tree instance as the left child of this node.
		void ins_left(Binary_Tree* data);

		// Insert a Binary Tree instance as the right child of this node.
		void ins_right(Binary_Tree* data);



		// ------------------------- DELETE FUNCTIONS --------------------------

		// Deallocate the tree of the left recursively. Set left to nullptr.
		void del_left();

		// Deallocate the tree of the right recursively. Set right to nullptr.
		void del_right();



		// ------------------------------ GETTERS ------------------------------

		// Get the value of this node.
		T get_value();

		// Get pointer of the left child.
		Binary_Tree<T>* left_child();

		// Get poiner of the right child.
		Binary_Tree<T>* right_child();

	protected:
		T data;
		Binary_Tree<T>* left;
		Binary_Tree<T>* right;
	};



	// -------------------------- BINARY SEARCH TREE ---------------------------

	template <typename T>
	class BST
	{
	public:
		// --------------------------- CONSTRUCTORS ----------------------------

		// Binary Search Tree constructor.
		BST(T data_val);

		// Binary Search Tree deep copy constructor.
		BST(const BST& source);

		// Binary Search Tree destructor.
		~BST();



		// ------------------------ TRIVIAL OPERATIONS -------------------------

		// Get value of the node.
		T get_value();

		// Returns true if both children are nullptr.
		bool is_leaf();



		// ----------------------- TRAVERSAL OPERATIONS ------------------------

		// Traversal inorder operation that returns a std::string.
		std::string inorder();

		// Traversal preorder operation that returns a std::string.
		std::string preorder();

		// Traversal postorder operation that returns a std::string.
		std::string postorder();

		// Helper for deletion method. Returns inorder successor's pointer.
		BST* inorder_successor();



		// -------------------------- BST OPEARTIONS ---------------------------
		// Operations for searching, inserting, and deleting nodes to the BST
		// maintaining its structure.

		// Returns pointer to node that cointains the search_value (key).
		BST* search(T search_value);

		// Inserts a new node with the given value to the BST.
		BST* insert(T new_val);

		// Properly deletes the node containing the given value.
		BST* del(T val_to_del);

	protected:
		T data;
		BST<T>* left;
		BST<T>* right;
	};
}

#endif
