#include "avl.h"
#include <iostream>
#include <queue>

using namespace std;

int computeHeight(Node *root) {
    if (root == nullptr) {
        return -1;
    }
    else {
        int hLeft = computeHeight(root->left);

        int hRight = computeHeight(root->right);

        return std::max(hLeft, hRight) + 1; 
    }
}

Node* LeftRotate (Node *& node) {
    Node *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    node = tmp;

    tmp->height = computeHeight(tmp);
    node->height = computeHeight(node);



    return tmp;
}

Node* RightRotate (Node *& node) {
    Node *tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    node = tmp;

    tmp->height = computeHeight(tmp);
    node->height = computeHeight(node);

    return tmp;
}

Node* recursive_insert(Node* node, const int &v) {
    if (node == nullptr) {
        Node* temp = new Node(v);
        node = temp;
    }
    else if (node->val > v) {
        node->left = recursive_insert(node->left, v);
    } 
    else if (node->val < v) {
        node->right = recursive_insert(node->right, v);
    }
    else { 
        return node; 
    }

    int bf = computeHeight(node->left) - computeHeight(node->right);

        if (bf > 1 and v < node->left->val) {
            return RightRotate(node);
        }
        else if (bf > 1 and v > node->left->val) {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }

        if (bf < -1 and v > node->right->val) {
            return LeftRotate(node);
        }
        else if (bf < -1 and v < node->right->val) {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }

    node->height = computeHeight(node);
    return node;
}

//end of helper functions

void AVL::rotateLeft(Node *& node) {
    Node *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    node = tmp;
    return;
}

void AVL::rotateRight(Node *& node) {
    Node *tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    node = tmp;
    return;
}

void AVL::rotateLeftRight(Node *& node) {
    rotateLeft(node->left);
    rotateRight(node);
    return;
}

void AVL::rotateRightLeft(Node *& node) {
    rotateRight(node->right);
    rotateLeft(node);
    return;
}

int getHeight(Node *node) {
    return node == nullptr ? -1 : node->height;
}

void printBT(const string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        int balance = computeHeight(node->left) - computeHeight(node->right);
        // print the value of the node
        cout << " " << node->val << "," << node->height << "," << balance << endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);    
}

void AVL::insert(const int &v) {
    root = recursive_insert(root, v);
    //printBT(root);
    //cout << "-------------------" << endl;
}
