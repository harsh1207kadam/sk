#include <iostream>
using namespace std;


class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int d, Node* n = nullptr, Node* p = nullptr) : data(d), next(n), prev(p) {}
    };


    Node* head;
    Node* tail;
    int size;


public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}


    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }


    void insertAtBeginning(int data) {
        Node* newNode = new Node(data, head, nullptr);
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        size++;
    }


    void insertAtEnd(int data) {
        Node* newNode = new Node(data, nullptr, tail);
        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        size++;
    }


    void insertAfter(int existingData, int newData) {
        Node* current = head;
        while (current != nullptr && current->data != existingData) {
            current = current->next;
        }
        if (current != nullptr) {
            Node* newNode = new Node(newData, current->next, current);
            if (current->next != nullptr) {
                current->next->prev = newNode;
            } else {
                tail = newNode;
            }
            current->next = newNode;
            size++;
        } else {
            cout << existingData << " not found in the list.\n";
        }
    }


    void deleteElement(int data) {
        Node* current = head;
        while (current != nullptr && current->data != data) {
            current = current->next;
        }
        if (current != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            size--;
        } else {
            cout << data << " not found in the list.\n";
        }
    }


    void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
        } else {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};


int main() {
    DoublyLinkedList list;


    int choice, element, existingElement;


    while (true) {
        cout << "Menu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after existing element\n";
        cout << "4. Delete element\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
            case 1:
                cout << "Enter element to insert at beginning: ";
                cin >> element;
                list.insertAtBeginning(element);
                                break;
            case 2:
                cout << "Enter element to insert at end: ";
                cin >> element;
                list.insertAtEnd(element);
                break;
            case 3:
                cout << "Enter existing element: ";
                cin >> existingElement;
                cout << "Enter element to insert after " << existingElement << ": ";
                cin >> element;
                list.insertAfter(existingElement, element);
                break;
            case 4:
                cout << "Enter element to delete: ";
                cin >> element;
                list.deleteElement(element);
                break;
            case 5:
                list.displayList();
                break;
            case 6:
                cout << "Exiting program...\n";
                exit(0);
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }


    return 0;
}
