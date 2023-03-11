#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList();

    void addLast(int value);
    void addFirst(int value);
    bool remove(int value);
    void copyFirstToLast();
    void printList();
};

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::addLast(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::addFirst(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

bool LinkedList::remove(int value) {
    if (head == nullptr) {
        return false;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return false;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return true;
}

void LinkedList::copyFirstToLast() {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    Node* newNode = new Node;
    newNode->data = head->data;
    newNode->next = nullptr;
    current->next = newNode;
}

void LinkedList::printList() {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif
// its for program