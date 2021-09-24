#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        char ch;
        Node *left;
        Node *right;

        Node() {};
        Node(char c):ch(c){};
};

string decode(Node *root, string huffmanCode);


