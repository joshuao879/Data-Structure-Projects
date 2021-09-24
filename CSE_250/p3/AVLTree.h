#include <iostream>

template <class T>
class Node {
    public:
        Node();
        Node(const T &v) : val(v), left(NULL), right(NULL) {}
        Node *left;
        Node *right;
        int height;
        T val;
};

template <class T>
class AVLTree {
    public:
       AVLTree() : root(nullptr) {}
       void insert(const T& value);
       // void find(Node *& node, const T &value);
       void rotateLeft(Node<T> *& node);
       void rotateRight(Node<T> *& node);
       void rotateLeftRight(Node<T> *& node);
       void rotateRightLeft(Node<T> *& node);
        //void delete(const T &value);

    private:
        Node<T> *root;
};

template <typename T>
void inOrder(Node<T> *& root)  
{  
    if (root != NULL)  
    {  
        inOrder(root->left);
        std::cout << root->val << " ";  
        inOrder(root->right);  
    }  
}

template <class T>
void AVLTree<T>::rotateLeft(Node<T> *& node) {
    Node<T> *x = node->right;
    Node<T> *y = x->left;

    x->left = node;
    node->right = y;

    if (node->left->height > node->right->height) {
        node->height = node->left->height + 1;
    }
    else {
        node->height = node->right->height + 1;
    }

    if (x->left->height > x->right->height) {
        x->height = x->left->height + 1;
    }
    else {
        x->height = x->right->height + 1;
    }

}

template <class T>
void AVLTree<T>::rotateRight(Node<T> *& node) {
    Node<T> *x = node->left;
    Node<T> *y = x->right;

    x->right = node;
    node->left = y;

    if (node->left->height > node->right->height) {
        node->height = node->left->height + 1;
    }
    else {
        node->height = node->right->height + 1;
    }

    if (x->left->height > x->right->height) {
        x->height = x->left->height + 1;
    }
    else {
        x->height = x->right->height + 1;
    }

}

template <class T>
void AVLTree<T>::rotateLeftRight(Node<T> *& node) {

Node<T> *x = nullptr;
Node<T> *y = nullptr;
Node<T> *z = nullptr;

x = node;
y = node->left;
z = node->left->right;

x->left = z->right;
y->right = z->left;
z->right = x;
z->left = y;

} 

template <class T>
void AVLTree<T>::rotateRightLeft(Node<T> *& node) {
    Node<T> *x = nullptr;
    Node<T> *y = nullptr;
    Node<T> *z = nullptr;

    x = node;
    y = node->right;
    z = node->right->left;

    x->right = z->left;
    y->left = z->right;
    z->left = x;
    z->right = y;

}

template <class T>
void AVLTree<T>::insert(const T &value) {
    //for inserting in empty tree
    Node<T>* newNode = new Node<T>(value);
    if (root == nullptr) {
        //maybe change this if syntax sucks
        root = newNode;
    }

    //otherwise for normal binary tree insertion
    else {
    Node<T>* parent = nullptr;
    Node<T>* curr = root;
    
    while (curr != nullptr) {
        parent = curr;
        if (curr->val <= value) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }

    if (parent->val <= value) {
        parent->right = newNode;
    }
    else {
        parent->left = newNode;
    }

    if (newNode->left->height > newNode->right->height) {
        newNode->height = newNode->left->height + 1;
    }
    else {
         newNode->height = newNode->right->height + 1;
    }


    //AVL Correction Phase

    //might need to change the root node but for now leave as is;

    //change this to parent;

    int bf = parent->left->height - parent->right->height;


    if (bf > 1 and newNode->val < parent->left->val) {
        rotateRight(parent);
    }

    if (bf < -1 and newNode->val > parent->right->val) {
        rotateLeft(parent);
    }

    if (bf > 1 and newNode->val > parent->left->val) {
        rotateLeftRight(parent);
    }

    if (bf < -1 and newNode->val < parent->left->val) {
        rotateRightLeft(parent);
    }
    }
};



// template <class T>
// void AVLTree<T>::delete(const T &value) {
//     return;
// }

//helper functions:

