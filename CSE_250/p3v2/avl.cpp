#include "avl.h"
#include <iostream>
#include <queue>

using namespace std;

int computeHeight (Node *root) {
    if (root == nullptr) {
        return -1;
    }
    else {
        int hLeft = computeHeight(root->left);

        int hRight = computeHeight(root->right);

        return std::max(hLeft, hRight) + 1; 
    }
}

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

void AVL::insert(const int &v) {
    Node* newNode = new Node(v);
    // your code
    // <50 lines of code should be OK

    if (root == nullptr) {
        //maybe change this if syntax sucks
        root = newNode;
    }

    //otherwise for normal binary tree insertion

    Node* parent = nullptr;
    Node* curr = root;
    
    while (curr != nullptr) {
        parent = curr;
        if (curr->val <= newNode->val) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }

    if (parent->val <= newNode->val) {
        parent->right = newNode;
    }
    else {
        parent->left = newNode;
    }

    newNode->height = computeHeight(newNode);

    // if (newNode->left->height > newNode->right->height) {
    //     newNode->height = newNode->left->height + 1;
    // }
    // else {
    //      newNode->height = newNode->right->height + 1;
    // }

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

