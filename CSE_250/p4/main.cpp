#include <iostream>

#include "huffman.h"

int main() {

Node *root = new Node();
root->left = new Node('A'); // 0
root->right = new Node();
root->right->right = new Node('J'); //11
root->right->left = new Node('H'); //10

string code = "1011110";
string answer = decode(root, code);
cout << "decoded code: " << answer << endl;

}