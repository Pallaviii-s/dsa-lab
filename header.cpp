#ifndef LISTADT_H
#define LISTADT_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val);
};

class ListADT {
private:
    Node* head;
    Node* gethead();
public:
    ListADT();
    void insertAscending(int val);
    static ListADT merge(ListADT& list1, ListADT& list2);
    void display();
};

#endif
