#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Maximum size of the queue

class CircularQueue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    CircularQueue() {
        front = rear = -1; 
    }

    // check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    //  check if the queue is full
    bool isFull() {
        return (front == (rear + 1) % MAX_SIZE);
    }

    //  enqueue  an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // 
        } else {
            rear = (rear + 1) % MAX_SIZE; // Circular increment of rear
        }
        arr[rear] = value;
        cout << value << " enqueued to the queue." << endl;
    }

    // dequeue  an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued from the queue." << endl;
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % MAX_SIZE; // Circular increment of front
        }
    }

    // display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements in the queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX_SIZE; // Circular increment of index
        }
        cout << endl;
    }
};

int main() {
    CircularQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display();
    queue.dequeue();
    queue.display();
    queue.enqueue(4);
    queue.enqueue(5);
    queue.display();
    queue.enqueue(6); // This will show an error as the queue is full.
    return 0;
}
