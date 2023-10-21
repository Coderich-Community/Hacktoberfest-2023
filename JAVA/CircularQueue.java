// Description 
// A circular queue is a data structure that uses a fixed-size array to store elements,
// and it supports both enqueue (add elements) and dequeue (remove elements) operations.
// The circular queue overcomes the limitation of a regular queue, where the queue becomes
// full after a certain number of elements are added, making it inefficient for long-running applications.

// Implementation

public class CircularQueue {
    private int[] elements;
    private int front;  // Index of the front element
    private int rear;   // Index of the rear element
    private int size;   // Current number of elements
    private int capacity; // Maximum capacity of the queue

    public CircularQueue(int capacity) {
        this.capacity = capacity;
        this.elements = new int[capacity];
        this.front = 0;
        this.rear = -1;  // Initially, the queue is empty
        this.size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }

    public int size() {
        return size;
    }

    public void enqueue(int item) {
        if (isFull()) {
            System.out.println("Queue is full. Cannot enqueue.");
            return;
        }

        rear = (rear + 1) % capacity; // Wrap around if the rear pointer goes beyond the array size
        elements[rear] = item;
        size++;
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty. Cannot dequeue.");
            return -1; // You can choose a different error code or handle it differently
        }

        int item = elements[front];
        front = (front + 1) % capacity; // Wrap around if the front pointer goes beyond the array size
        size--;
        return item;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty.");
            return -1; // You can choose a different error code or handle it differently
        }
        return elements[front];
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty.");
            return;
        }

        int current = front;
        for (int i = 0; i < size; i++) {
            System.out.print(elements[current] + " ");
            current = (current + 1) % capacity;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        CircularQueue queue = new CircularQueue(5);

        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);

        System.out.print("Queue elements: ");
        queue.display();

        System.out.println("Dequeued item: " + queue.dequeue());
        System.out.println("Dequeued item: " + queue.dequeue());

        System.out.print("Queue elements after dequeuing: ");
        queue.display();

        queue.enqueue(6);
        queue.enqueue(7);

        System.out.print("Queue elements after enqueuing: ");
        queue.display();
    }
}
