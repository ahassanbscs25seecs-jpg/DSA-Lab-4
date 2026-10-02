#include <iostream>

struct Node {
    int data;
    Node *next;
};

class List {
public:
    List() : head{nullptr}, length{0} {}

    // This will also update the length of the list in order to avoid heavy computation
    // in the CountNodes function
    void AddNode(int addData) {
        Node *newNode = new Node();
        newNode->data = addData;
        newNode->next = nullptr;
        length++;

        // Case where the list is empty
        // Empty when head is nullptr
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Go to the end of the list and insert after the last node.
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    int CountNodes() {
        return length;
    }

    // Print the list out
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
    int length; // Will keep track of the number of nodes in linked list
};

// Run seperate tests for different number of inputs
void RunTest(int n) {
    List list;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "Enter value: ";
        std::cin >> value;
        list.AddNode(value);
    }

    std::cout << "List: ";
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;
    list.ClearList();
}

int main() {
    std::cout << "n = 0" << std::endl;
    RunTest(0);

    std::cout << "n = 1" << std::endl;
    RunTest(1);

    std::cout << "n = 5" << std::endl;
    RunTest(5);

    return 0;
}
