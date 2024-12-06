#include <iostream>
#include "BST.h"

int main() {
    BST* tree = new BST();

    // Insert nodes into the tree
    tree->insert(50);
    tree->insert(30);
    tree->insert(70);
    tree->insert(20);
    tree->insert(40);
    tree->insert(60);
    tree->insert(80);

    // In-order traversal of the tree
    std::cout << "In-order traversal: ";
    tree->inOrderTraversal();  // Expected: 20 30 40 50 60 70 80
    std::cout << std::endl;

    // Check if the tree contains specific values
    std::cout << "Does the tree contain 40? " << (tree->contains(40) ? "Yes" : "No") << std::endl;  // Expected: Yes
    std::cout << "Does the tree contain 90? " << (tree->contains(90) ? "Yes" : "No") << std::endl;  // Expected: No

    // Get the minimum and maximum values
    std::cout << "Minimum value in the tree: " << tree->min() << std::endl;  // Expected: 20
    std::cout << "Maximum value in the tree: " << tree->max() << std::endl;  // Expected: 80

    // Get the height of the tree
    std::cout << "Height of the tree: " << tree->height() << std::endl;  // Expected: 3 (if balanced)

    // Remove nodes from the tree
    tree->remove(20);  // Remove leaf node
    tree->remove(30);  // Remove node with one child
    tree->remove(70);  // Remove node with two children

    // In-order traversal after removal
    std::cout << "In-order traversal after removal: ";
    tree->inOrderTraversal();  // Expected: 40 50 60 80
    std::cout << std::endl;

    // Get the updated height of the tree
    std::cout << "Updated height of the tree: " << tree->height() << std::endl;  // Expected: 2 (if balanced)

    // Clean-up
    delete tree;
    return 0;
}