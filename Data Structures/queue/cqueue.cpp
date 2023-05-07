#include <iostream>

using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int itemCount;

public:
    CircularQueue() {
        arr = new int[SIZE];
        front = -1;
        rear = -1;
        itemCount = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (itemCount == 0);
    }

    bool isFull() {
        return (itemCount == SIZE);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue element." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        itemCount++;

        cout << "Enqueued " << value << " into the queue." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue element." << endl;
            return -1;
        }

        int dequeuedValue = arr[front];
        arr[front] = 0;
        front = (front + 1) % SIZE;
        itemCount--;

        cout << "Dequeued " << dequeuedValue << " from the queue." << endl;
        return dequeuedValue;
    }

    void deleteElement(int value) {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot delete element." << endl;
            return;
        }

        int count = 0;
        int i = front;

        while (count < itemCount) {
            if (arr[i] == value) {
                arr[i] = 0;
                cout << "Deleted " << value << " from the queue." << endl;
                return;
            }

            i = (i + 1) % SIZE;
            count++;
        }

        cout << "Element " << value << " not found in the queue." << endl;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int count = 0;
        int i = front;

        while (count < itemCount) {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
            count++;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue queue;
    int choice;
    int value;

    while (true) {
        cout << "Circular Queue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Delete Element" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout << "Enter the value to delete: ";
                cin >> value;
                queue.deleteElement(value);
                break;
            case 4:
                queue.displayQueue();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout<<"invalid"<<endl;
                break;
        }
    }        
}