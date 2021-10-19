// demo.cpp -- Demonstrates how to use the trees library.
#include "trees.hpp"
#include <iostream>

template <typename T>
void tratreop(rarm_trees::Binary_Tree<T> &node);
template <typename T>
void tratreop(rarm_trees::BST<T>& node);

int main(int argc, char* argv[])
{
    /* The section below demonstrates how to use general binary trees (no BST).
     * For Binary Search Trees look bellow this demonstrations.
    */

    std::cout << "Using general binary trees.\n";
    rarm_trees::Binary_Tree<std::string> my_node("A");
    
    // Children.
    my_node.manual_ins_left(new rarm_trees::Binary_Tree<std::string>("B"));
    my_node.manual_ins_right(new rarm_trees::Binary_Tree<std::string>("C"));

    // Adding children to the left branch.
    (*my_node.left_child()).manual_ins_left(new rarm_trees::Binary_Tree<std::string>("D"));
    (*my_node.left_child()).manual_ins_right(new rarm_trees::Binary_Tree<std::string>("E"));

    (*(*my_node.left_child()).right_child()).manual_ins_left(new rarm_trees::Binary_Tree<std::string>("H"));
    (*(*my_node.left_child()).right_child()).manual_ins_right(new rarm_trees::Binary_Tree<std::string>("I"));

    // Adding children to thre right branch.
    (*my_node.right_child()).manual_ins_left(new rarm_trees::Binary_Tree<std::string>("F"));
    (*my_node.right_child()).manual_ins_right(new rarm_trees::Binary_Tree<std::string>("G"));

    // Printing values.
    std::cout << "The value of the created node is: " << my_node.get_value() << "\n\n";

    // Printing traversal operations.
    tratreop(my_node);



    /* This section demonstrates how to work with Binary Search Trees using the trees library.
     * UNDER CONSTRUCTION.
    */
    std::cout << "Using the binary search trees.\n\n";

    // Creating a single BST node.
    rarm_trees::BST<int> bst_node{ 10 };

    std::cout << "The value of the root of the BST is: " << bst_node.get_value() << "\n\n";

    // Inserting values to the BST.
    bst_node.insert(5);
    bst_node.insert(2);

    bst_node.insert(15);
    bst_node.insert(12);
    bst_node.insert(20);

    // Reading traversal of BST.
    tratreop(bst_node);

    // Using the inorder_successor method.
    std::cout << "The inorder successor of " << bst_node.get_value() << " is: " << (*bst_node.inorder_successor()).get_value() << ".\n\n";

    // Search a specific node in the tree.
    rarm_trees::BST<int> search_val = *bst_node.search(15);

    // Printing traversal operations of the found node.
    // It should print only tree values.
    tratreop(search_val);

    // Inserting a value that already exists in the BST should not modify it.
    search_val.insert(12);
    tratreop(search_val);

    // Creating a new BST to test deletion.
    rarm_trees::BST<int> bst_root(5);
    bst_root.insert(2);
    bst_root.insert(-4);
    bst_root.insert(3);

    bst_root.insert(12);
    bst_root.insert(9);
    bst_root.insert(21);
    bst_root.insert(21);
    bst_root.insert(25);

    std::cout << "\nCreating a new Binary Search Tree.\n";
    tratreop(bst_root);

    std::cout << "Deleting 12 from the tree.\n";
    bst_root.del(12);
    tratreop(bst_root);

    return 0;
}



// Traversal Tree Operaions
// Print all traversal operations (inorder, preorder, and postorder) of a tree given the root node.
template <typename T>
void tratreop(rarm_trees::Binary_Tree<T>& node)
{
    std::cout << "Traversal operations of the Binary Tree:\n"
              << "inorder: " << node.inorder() << "\n"
              << "preorder: " << node.preorder() << "\n"
              << "postorder: " << node.postorder() << "\n\n";
    return;
}

// Traversal Tree Operaions
// Print all traversal operations (inorder, preorder, and postorder) of a tree given the root node.
template <typename T>
void tratreop(rarm_trees::BST<T>& node)
{
    std::cout << "Traversal operations of the BST:\n"
              << "inorder: " << node.inorder() << "\n"
              << "preorder: " << node.preorder() << "\n"
              << "postorder: " << node.postorder() << "\n\n";
    return;
}