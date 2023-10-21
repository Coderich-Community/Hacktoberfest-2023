#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, maxSize;

public:
    CircularQueue(int size) {
        maxSize = size + 1;  // One extra space to differentiate between front and rear.
        arr = new int[maxSize];
        front = rear = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        arr[rear] = value;
        rear = (rear + 1) % maxSize;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value indicating an error
        }

        int value = arr[front];
        front = (front + 1) % maxSize;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1; // Return a sentinel value indicating an error
        }

        return arr[front];
    }
};

int main() {
    CircularQueue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    cout << "Front element: " << queue.peek() << endl;

    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " ";
    }

    cout << endl;

    // Try to dequeue from an empty queue
    cout << "Dequeue from empty queue: " << queue.dequeue() << endl;

    return 0;
}
