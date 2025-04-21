#pragma once

//Single linked list again
struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    void addHead(const int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    
    LinkedList reverseList() const {
        int length = 0;
        Node* temp = head;
        LinkedList reverseList;

        while (temp != nullptr) {
            reverseList.addHead(temp->data);
            temp = temp->next;
        }

        return reverseList;
    }

    Node* head = nullptr;
};
