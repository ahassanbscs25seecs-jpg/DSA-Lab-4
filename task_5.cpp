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

    // Delete the first node that contains the value
    // that we passed it
    void DeleteNode(int delData) {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node *current = head;
        Node *previous = nullptr;

        // Traverse the list and see which node has our target value
        while (current != nullptr && current->data != delData) {
            previous = current;
            current = current->next;
        }

        // The value wasn't found
        if (current == nullptr) {
            std::cout << "Value not found." << std::endl;
            return;
        }


        if (previous == nullptr) { // If the node is head
            head = current->next;
        } else { // if the node is anywhere else in the list
            previous->next = current->next;
        }

        
        delete current;
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
        length = 0;
        head = nullptr;
    }

private:
    Node *head;
    int length;
};

int main() {
    List list;

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);

    std::cout << "Before delete: ";
    list.PrintList();

    list.DeleteNode(20);
    std::cout << "After deleting 20: ";
    list.PrintList();

    // Deleting from an empty list. Shouldn't work
    List emptyList;
    emptyList.DeleteNode(20);

    // Deleting a non existent value. Should fail as well
    List missingList;
    missingList.AddNode(10);
    missingList.AddNode(30);
    missingList.DeleteNode(20);

    List oneNodeList;
    oneNodeList.AddNode(40);
    oneNodeList.DeleteNode(40);
    std::cout << "After deleting only node: ";
    oneNodeList.PrintList();

    list.ClearList();
    emptyList.ClearList();
    missingList.ClearList();
    oneNodeList.ClearList();

    return 0;
}
