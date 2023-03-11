#include <iostream>

using namespace std;
class Node {
public:
    int value;
    Node* next;
};

class LinkedList {
public:
    LinkedList();
    void addNode(int value);
    void addNodeAtBeginning(int value);
    void deleteNode(int value);
    void copyFirstNodeToEnd();
    void printList();
private:
    Node* head;
};

LinkedList::LinkedList() {
    head = nullptr;
}


void LinkedList::addNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::printList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
}
void LinkedList::addNodeAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}
void LinkedList::deleteNode(int value) {
    Node* currentNode = head;
    Node* previousNode = nullptr;

    while (currentNode != nullptr) {
        if (currentNode->value == value) {
            if (previousNode != nullptr) {
                previousNode->next = currentNode->next;
            } else {
                head = currentNode->next;
            }
            delete currentNode;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}
void LinkedList::copyFirstNodeToEnd() {
    if (head == nullptr) {
        return;
    }

    Node* currentNode = head;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    Node* newNode = new Node;
    newNode->value = head->value;
    newNode->next = nullptr;
    currentNode->next = newNode;
}

int main() {
    LinkedList list;
    list.addNode(10);
    list.addNode(20);
    list.addNode(30);
    list.addNodeAtBeginning(1);
    list.deleteNode(20);
    list.copyFirstNodeToEnd();
    list.printList(); 
    return 0;
}

//its test