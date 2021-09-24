#include <iostream>
#include <string>

#include "huffman.h"

using namespace std;

string decode(Node *root, string huffmanCode) {
    string result;
    int j = 0;

   while (j < huffmanCode.length()) {
        Node *temp = root;
        while (temp->ch == '\0') {
            if (huffmanCode[j] == '1') {
                temp = temp->right;
            }
            else if (huffmanCode[j] != '1') {
                temp = temp->left;
            }
            j++;
        }
         result += temp->ch;
    }
return result; 
}