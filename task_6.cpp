#include <iostream>

struct Node {
    int data;
    Node *next;
};

class List {
public:
    List() : head{nullptr}, length{0} {}

    void AddNode(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        length++;

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

    void InsertAtBeginning(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        length++;
    }

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

        std::cout << "Value not found." << std::endl;
    }

    void DeleteNode(int delData) {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node *current = head;
        Node *previous = nullptr;

        while (current != nullptr && current->data != delData) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Value not found." << std::endl;
            return;
        }

        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        length--;
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

    int CountNodes() {
        return length;
    }

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
    int choice = 0;

    while (true) {
        // Display all the options the user can select
        std::cout << "\n1. Insert at beginning" << std::endl;
        std::cout << "2. Insert at end" << std::endl;
        std::cout << "3. Search by value" << std::endl;
        std::cout << "4. Delete by value" << std::endl;
        std::cout << "5. Display all nodes" << std::endl;
        std::cout << "6. Count nodes" << std::endl;
        std::cout << "7. Display second node" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int value;
            std::cout << "Enter value: ";
            std::cin >> value;
            list.InsertAtBeginning(value);
        } else if (choice == 2) {
            int value;
            std::cout << "Enter value: ";
            std::cin >> value;
            list.AddNode(value);
        } else if (choice == 3) {
            int value;
            std::cout << "Enter value to search: ";
            std::cin >> value;
            list.SearchNode(value);
        } else if (choice == 4) {
            int value;
            std::cout << "Enter value to delete: ";
            std::cin >> value;
            list.DeleteNode(value);
        } else if (choice == 5) {
            list.PrintList();
        } else if (choice == 6) {
            std::cout << "Node count: " << list.CountNodes() << std::endl;
        } else if (choice == 7) {
            list.PrintSecondNode();
        } else if (choice == 8) {
            break;
        } else {
            std::cout << "Invalid choice." << std::endl;
        }
    }

    list.ClearList();
    std::cout << "Program ended." << std::endl;
    return 0;
}
