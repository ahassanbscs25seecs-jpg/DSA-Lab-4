#include <iostream>

struct Node {
    int data;
    Node *next;
};

class List {
public:
    List() : head(nullptr) {}

    void AddNode(int addData) {
        Node *newNode = new Node();
        newNode->data = addData;
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

    // Traverse the linked list, find and print out the
    // position of the first node that contains the data we want to find
    void SearchNode(int searchData) {
        int position = 1;
        Node *current = head;

        while (current != nullptr) {
            if (current->data == searchData) {
                std::cout << "Position: " << position << std::endl;
                return;
            }
            current = current->next;
            position++;
        }

        std::cout << "Value not found" << std::endl;
    }

    // Traverse the list till we encounter the second node
    void PrintSecondNode() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node *current = head;
        if (current->next == nullptr) {
            std::cout << "Only one node exists." << std::endl;
            return;
        }

        current = current->next;
        std::cout << "Second node: " << current->data << std::endl;
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
    // Test searching on an empty list
    List emptyList;
    std::cout << "Empty list:" << std::endl;
    emptyList.PrintSecondNode();
    emptyList.SearchNode(20);

    // Test with a one length linked list
    List oneNodeList;
    oneNodeList.AddNode(10);
    std::cout << "One node list:" << std::endl;
    oneNodeList.PrintSecondNode();

    // Test with a longer linked list
    List list;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.AddNode(20);

    std::cout << "List:" << std::endl;
    list.PrintList();

    std::cout << "Search 20:" << std::endl;
    list.SearchNode(20);

    std::cout << "Search 99:" << std::endl;
    list.SearchNode(99);

    std::cout << "Second node:" << std::endl;
    list.PrintSecondNode();

    return 0;
}
