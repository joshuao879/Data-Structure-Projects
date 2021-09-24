#include <iostream>

#include "List.h"

using std::cout;
using std::endl;


namespace ds {
    Node::Node() {
        prev = nullptr;
        next = nullptr;
    }

    Node::Node(int v){
        val = v;
    }

    DoublyLinkedList::DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    DoublyLinkedList::DoublyLinkedList(int arr[], int size)  {

        if (size == 0) {
            head = tail = nullptr;
            length == 0;
        }
       
       else {
        Node* headvalue = new Node(arr[0]);
        head = headvalue; 
        head->next = nullptr;
        head->prev = nullptr;
        tail = head; 

    
        for (int i = 1; i < size; i++) {
            Node* temp = new Node(arr[i]);
            temp->next = tail->next; 
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        length = size; 
       }
    }
    
    void DoublyLinkedList::Insert(int idx, int v) {

       Node *insert = new Node(v);
       insert->next = nullptr;
       insert->prev = nullptr;

       if (idx < 0 or idx > length) {
           return;
       }

       if (idx == 0) {
        if (length == 0) {
            head = tail = insert;
            length += 1; 
           }
        else {
           insert->next = head; 
           head->prev = insert; 
           head = insert; 
           length += 1;
            }
       }

     else {
           Node *prevNode = head; 
           for (int j = 0; j < idx-1; j++) {
              prevNode = prevNode->next; 
           }
           if (prevNode->next != nullptr) {
               Node *t = nullptr;
               t = prevNode->next;
               prevNode->next = insert;
               t->prev = insert;
               insert->next = t;
               insert->prev = prevNode;
               length += 1;
           }
           else {
               insert->next = nullptr; 
               insert->prev = tail;
               tail->next = insert;
               tail = insert; 
               length += 1;
           }
       }
    }

    void DoublyLinkedList::Remove(int idx) {
        Node *now = head;
        Node *beforenow = nullptr;

        if (idx < 0 or idx >= length) {
            return;
        }
 
        if (idx == 0) {
            if (length == 1) {
                    Node* t = new Node();
                    Node* nextHead = head->next; 
                    t = head;
                    delete t;
                    head = nextHead; 
                    length -= 1;
                    head = tail = nullptr;
        }
             else {
                  head = head->next;
                  head->prev = nullptr;
                  delete now;
                  length -= 1;
             }
        }
    else {
        for (int j = 0; j < idx; j++) {
            now = now->next; 
        }

        //For Most Cases
        if (now->next != nullptr) {
            beforenow = now->prev;
            beforenow->next = now->next; 
            now->next->prev = beforenow;
            delete now;
            length -= 1;
        }


        //For Tail. From Sheng Liu Lecture
        else {
            Node *headptr = head;
            Node *tempnode = head->next;
        

            while (tempnode->next != nullptr) {
                headptr = tempnode; 
                tempnode = tempnode->next; 
            }

            tail = headptr;
            headptr->next = nullptr;
            delete tempnode;
            length -= 1;
        }
    }
    }

    int DoublyLinkedList::Get(int idx) {
        Node *node = head;
        int counter = 0;
        int match = false;
        while (node != nullptr) {
            if (counter == idx) {
                int result = node->val;
                match = true;
                return result;
            }
            counter++;
            node = node->next;
        }
        if (match == false) {
            return -1;
        }
    }

    int DoublyLinkedList::Search(int v) {
        Node *current = head;
        Node *newNode;
        bool match = false; 
        int position = 0; 

        while (current != nullptr) {
            if (v == current->val) {
                match == true; 
                return position;
            }
            current = current->next;
            position++;
        }

        if (match == false) {
            return -1; 
        }
    }

    void DoublyLinkedList::ReverseList()  {
       Node *t = head; 
       Node *t2 = nullptr;

       if (t == nullptr) {
           return;
       }

       else {

        while (t != nullptr) {
            t2 = t->next; 
            t->next = t->prev;
            t->prev = t2;
            t = t2; 
        }

        t = head;
        head = tail;
        tail = t; 
       }
    }

    void DoublyLinkedList::PrintList()  {
        if (head == nullptr) {
            cout << "Empty List" << endl;
        }
        else {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->val << "->";
                temp = temp->next; 
            }
            cout << endl;
        }
    }

    void DoublyLinkedList::MergeList(DoublyLinkedList *list) {
        Node *current = head;
        Node *currentlist = list->head; 
 
        if (currentlist == nullptr) {
            return; 
        }

        tail->next = currentlist;
        currentlist->prev = tail;

        tail = list->tail;
        length = length + list->length;

    }
}