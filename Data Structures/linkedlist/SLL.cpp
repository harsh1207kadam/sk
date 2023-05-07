#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
};


class SinglyLinkedList {
private:
    Node* head;


public:
    SinglyLinkedList() {
        head = NULL;
    }


    void insertAtBeginning(int element) {
        Node* newNode = new Node();
        newNode->data = element;
        newNode->next = head;
        head = newNode;
        cout << element << " inserted at beginning successfully.\n";
    }


    void insertAtEnd(int element) {
        Node* newNode = new Node();
        newNode->data = element;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << element << " inserted at end successfully.\n";
    }


    void insertAfter(int existingElement, int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;
        if (head == NULL) {
            cout << "List is empty. Cannot insert after " << existingElement << ".\n";
        } else {
            Node* temp = head;
            while (temp != NULL && temp->data != existingElement) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << existingElement << " not found in the list. Cannot insert " << newElement << " after it.\n";
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << newElement << " inserted after " << existingElement << " successfully.\n";
            }
        }
    }


    void deleteElement(int element) {
        if (head == NULL) {
            cout << " not found " << element << ".\n";
        } else {
            Node* temp = head;
            Node* prev = NULL;
            while (temp != NULL && temp->data != element) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << element << " not found \n";
            } else {
                if (prev == NULL) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << element << " deleted successfully.\n";
            }
        }
    }


    void displayList() {
        if (head == NULL) {
            cout << "List is empty.\n";
        } else {
            Node* temp = head;
            cout << "List contents: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};


int main() {
    SinglyLinkedList list;
    int choice, element, existingElement;


    while (true) {
        cout << "\nMENU\n";
        cout << "1. Insert element at beginning\n";
        cout << "2. Insert element at end\n";
        cout << "3. Insert element after some element\n";
        cout << "4. Delete element\n";
        cout << "5. Display list contents\n";
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
            cout << "Enter existing element after which new element is to be inserted: ";
            cin >> existingElement;
            cout << "Enter new element to insert: ";
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
            cout << "Exiting program...";
            exit(0);


        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }
}


return 0;
}
