#include <iostream>
#include <vector>

using namespace std; // Add this line to use the std namespace

class Stack {
private:
    vector<int> stack;

public:
    void push(int value) {
        stack.push_back(value);
    }

    void pop() {
        if (!isEmpty()) {
            stack.pop_back();
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    int top() {
        if (!isEmpty()) {
            return stack.back();
        } else {
            cout << "Stack is empty. No top element." << endl;
            return -1; // Return a default value indicating an empty stack.
        }
    }

    bool isEmpty() {
        return stack.empty();
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element: " << myStack.top() << endl;

    myStack.pop();
    myStack.pop();

    cout << "Top element after pops: " << myStack.top() << endl;

    myStack.pop();
    myStack.pop(); // Trying  pop from an empty stack

    return 0;
}
