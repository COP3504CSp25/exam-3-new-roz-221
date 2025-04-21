#pragma once

//Single linked list, not double
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

    int* getStats() const{
        int stats[3];
        std::vector<int> values;
        int sum = 0;

        Node* temp = head;
        while(temp != nullptr) {
            values.push_back(temp->data);
            sum += temp->data;
            temp = temp->next;
        }

        // Minimum
        int min = values.at(0);
        for (size_t i = 0; i < values.size(); i++){
            if (values.at(i) <= min) {
                min = values.at(i);
            }
        }
        stats[0] = min;

        // Maximum
        int max = values.at(0);
        for (size_t i = 0; i < values.size(); i++){
            if (values.at(i) >= max) {
                max = values.at(i);
            }
        }
        stats[1] = max;

        // Mean
        stats[2] = (sum / values.size());

        return *stats[0];
    }
    

private:
    Node* head = nullptr;
};
