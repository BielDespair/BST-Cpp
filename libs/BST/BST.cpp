#include "BST.h"
#include <iostream>

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    this->cleanup(this->root);
}

void BST::cleanup(node* root) {
    if (root == nullptr) {
        return;
    }
    this->cleanup(root->pleft);
    this->cleanup(root->pright);
    std::cout << "Deleted node " << root->data << std::endl;
    delete root;
}

BST::node* BST::insert(int data, node* root) {
    if (root == nullptr) {
        return new node(data);
    }
    if (data < root->data) {
        root->pleft = this->insert(data, root->pleft);
    }
    else {
        root->pright = this->insert(data, root->pright);
    }
    return root;
}

BST::node* BST::remove(int data, node* root) {
    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->pleft = remove(data, root->pleft);
    }
    else if (data > root->data) {
        root->pright = remove(data, root->pright);
    }
    else {
        if (root->pleft == nullptr && root->pright == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->pleft == nullptr) {
            node* temp = root;
            root = root->pright;
            delete temp;
            return root;
        }
        else if (root->pright == nullptr) {
            node* temp = root;
            root = root->pleft;
            delete temp;
            return root;
        }
        else {
            node* successor = this->findSuccessor(root->pright);
            root->data = successor->data;
            root->pright = remove(successor->data, root->pright);
        }
    }
    return root;
}

BST::node* BST::findSuccessor(node* root) {
    if (root->pleft == nullptr) {
        return root;
    }
    return this->findSuccessor(root->pleft);
}

void BST::inOrderTraversal(node* root) {
    if (root == nullptr) {
        return;
    }
    this->inOrderTraversal(root->pleft);
    std::cout << root->data << " ";
    this->inOrderTraversal(root->pright);
}

bool BST::contains(int data, node* root) {
    if (root == nullptr) {
        return false;
    }
    if (data == root->data) {
        return true;
    }
    if (data < root->data) {
        return this->contains(data, root->pleft);
    }
    return this->contains(data, root->pright);
}
int BST::min(node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->pleft == nullptr) {
        return root->data;
    }
    return this->min(root->pleft);
}

int BST::max(node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->pright == nullptr) {
        return root->data;
    }
    return this->max(root->pright);
}

int BST::height(node* root) {
    if (root == nullptr) {
        return 0;
    }
    int lheight = this->height(root->pleft);
    int rheight = this->height(root->pright);
    return (lheight > rheight) ? (1+lheight) : (1+rheight);
}

void BST::insert(int data) {
    this->root = this->insert(data, this->root);
}

void BST::remove(int data) {
    this->root = this->remove(data, this->root);
}

bool BST::contains(int data) {
    return this->contains(data, this->root);
}
int BST::min() {
    return this->min(this->root);
}
int BST::max(){
    return this->max(this->root);
}

int BST::height() {
    return this->height(this->root);
}

void BST::inOrderTraversal() {
    this->inOrderTraversal(this->root);
    std::cout << std::endl;
}