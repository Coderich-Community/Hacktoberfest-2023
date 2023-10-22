#include <iostream>
using namespace std;

#define MAX_SIZE 5

class CircularQueue {
private:
    int* arr;
    int maxSize;
    int front, rear;

public:
    // Constructor initializes front and rear to -1 indicating an empty queue
     CircularQueue(int size) : maxSize(size), front(-1), rear(-1) {
        arr = new int[maxSize];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == (rear + 1) % MAX_SIZE);
    }

    // Function to enqueue an element to the queue
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue element." << endl;
        } else {
            // If the queue is empty, set front and rear to 0
            if (isEmpty()) {
                front = rear = 0;
            } else {
                // Circularly increment rear index
                rear = (rear + 1) % MAX_SIZE;
            }
            arr[rear] = item;
            cout << item << " enqueued to the queue." << endl;
        }
    }

    // Function to dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue element." << endl;
        } else {
            int removedItem = arr[front];
            // If there is only one element in the queue, reset front and rear to -1
            if (front == rear) {
                front = rear = -1;
            } else {
                // Circularly increment front index
                front = (front + 1) % MAX_SIZE;
            }
            cout << removedItem << " dequeued from the queue." << endl;
        }
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            int i = front;
            cout << "Queue: ";
            // Loop through the queue elements using circular index calculation
            do {
                cout << arr[i] << " ";
                i = (i + 1) % MAX_SIZE;
            } while (i != (rear + 1) % MAX_SIZE);
            cout << endl;
        }
    }

    // Destructor to release dynamically allocated memory
    ~CircularQueue() {
        delete[] arr;
    }

};

// Driver program
int main() {
    int maxSize;
    cout << "Enter the maximum size of the circular queue: ";
    cin >> maxSize;

    CircularQueue queue(maxSize);

    // Enqueue elements to the queue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display(); // Queue: 1 2 3

    // Dequeue an element and display the queue
    queue.dequeue();
    queue.display(); // Queue: 2 3

    // Enqueue more elements
    queue.enqueue(4);
    queue.enqueue(5);
    queue.display(); // Queue: 2 3 4 5

    // Attempt to enqueue when the queue is full
    queue.enqueue(6); // Queue is full, cannot enqueue 6

    // Dequeue all elements from the queue
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); // Queue is empty, cannot dequeue further

    return 0;
}
