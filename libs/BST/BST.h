#ifndef BST_H
#define BST_H

class BST {
    private:
        struct node {
            int data;
            node* pleft;
            node* pright;

            node(int data) : data(data), pleft(nullptr), pright(nullptr) {};

        };
        void cleanup(node* root);
        node* root;
        node* insert(int data, node* root);
        node* findSuccessor(node* root);
        node* remove(int data, node* root);
        bool contains(int data, node* root);
        int min(node* root);
        int max(node *root);
        int height(node* root);
        void inOrderTraversal(node* root);
    public:
        BST();
        ~BST();
        void insert(int data);
        void remove(int data);
        bool contains(int data);
        int min();
        int max();
        int height();
        void inOrderTraversal();
};

#endif //BST_H