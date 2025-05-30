//#pragma once
#include <vector>
#include <cmath>

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

        const size_t size = 3;
        int* stats = new int[size];
        std::vector<int> values;
        int sum = 0;

        if (head == nullptr) {
            stats[0] = 0;
            stats[1] = 0;
            stats[2] = 0;
        }

        else {
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
            stats[2] = static_cast<int>(floor(sum / values.size()));
        }
        return stats;
    }
    
private:
    Node* head = nullptr;
};