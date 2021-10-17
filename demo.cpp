// demo.cpp -- Demonstrates how to use the trees library.
#include "trees.hpp"
#include <iostream>

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
    std::cout << "Traversal operations:\n"
              << "inorder: " << my_node.inorder() << "\n"
              << "preorder: " << my_node.preorder() << "\n"
              << "postorder: " << my_node.postorder() << "\n\n\n";



    /* This section demonstrates how to work with Binary Search Trees using the trees library.
     * UNDER CONSTRUCTION.
    */
    std::cout << "Using the binary search trees.\n";

    // Creating a single BST node.
    rarm_trees::BST<int> bst_node{ 5 };

    std::cout << "The value of the root of the BST is: " << bst_node.get_value() << "\n";

    return 0;
}