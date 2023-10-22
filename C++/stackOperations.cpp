#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
    // Push element onto the stack
    void push(int value) {
        data.push_back(value);
    }

    // Remove and return the top element from the stack
    int pop() {
        if (!data.empty()) {
            int top = data.back();
            data.pop_back();
            return top;
        }
        throw std::runtime_error("Stack is empty");
    }

    // Get the top element of the stack without removing it
    int top() {
        if (!data.empty()) {
            return data.back();
        }
        throw std::runtime_error("Stack is empty");
    }

    // Check if the stack is empty
    bool isEmpty() {
        return data.empty();
    }

    // Get the size of the stack
    size_t size() {
        return data.size();
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();

    std::cout << "Top element after pop: " << stack.top() << std::endl;

    std::cout << "Stack size: " << stack.size() << std::endl;

    return 0;
}
