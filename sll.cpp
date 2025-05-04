#include "ListADT.h"

Node::Node(int val) {
    data = val;
    next = nullptr;
}

ListADT::ListADT() {
    head = nullptr;
}

Node* ListADT::gethead() {
    return head;
}

void ListADT::insertAscending(int val) {
    Node* newNode = new Node(val);
    if (!head || head->data >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data < val)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

ListADT ListADT::merge(ListADT& list1, ListADT& list2) {
    ListADT mergedList;
    Node* t1 = list1.gethead();
    Node* t2 = list2.gethead();
    while (t1) {
        mergedList.insertAscending(t1->data);
        t1 = t1->next;
    }
    while (t2) {
        mergedList.insertAscending(t2->data);
        t2 = t2->next;
    }
    return mergedList;
}

void ListADT::display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
