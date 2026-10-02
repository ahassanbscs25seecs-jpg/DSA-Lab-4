#include <iostream>

struct Node {
    int data;
    Node *next;
};

class List {
public:
    List() : head(nullptr) {}

    void AddNode(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Insert before the head node
    // We'll have to update the head node after this operation.
    void InsertAtBeginning(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

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

private:
    Node *head;
};

int main() {
    List list;

    // Test by putting elements at the beginning
    // and print the list everytime

    list.InsertAtBeginning(20);
    std::cout << "After insert 20 at beginning: ";
    list.PrintList();

    list.InsertAtBeginning(10);
    std::cout << "After insert 10 at beginning: ";
    list.PrintList();

    list.AddNode(30);
    std::cout << "After append 30: ";
    list.PrintList();

    list.ClearList();
    return 0;
}
