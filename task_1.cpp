#include <iostream>

// Represents a single element in a linked list
// Is singly linked (only next pointer available)
struct Node {
    int data;
    Node *next;
};

// Represents a singly linked list along with some helper functions to interact with it
class List {
public:
    List() : head(nullptr) {}

    void PrintList() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node *current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    void ClearList() {
        Node *current = head;
        while (current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    Node *head;
};

void CreateThreeNodes(List &list) {
    int value;
    Node *last = nullptr;

    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter a number: ";
        std::cin >> value;

        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (list.head == nullptr) {
            list.head = newNode;
        } else {
            last->next = newNode;
        }

        last = newNode;
    }
}

int main() {
    List list;

    std::cout << "List before creation: ";
    list.PrintList();

    CreateThreeNodes(list);
    std::cout << "List after creation: ";
    list.PrintList();

    list.ClearList();
    std::cout << "List after cleanup: ";
    list.PrintList();

    return 0;
}
