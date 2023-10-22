#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueues {
public:
    void push(int x) {
        tempQueue.push(x);
        while (!mainQueue.empty()) {
            tempQueue.push(mainQueue.front());
            mainQueue.pop();
        }

        // Swap the main and temporary queues (main = temp, temp = empty)
        mainQueue.swap(tempQueue);
    }

    void pop() {
        mainQueue.pop();
    }

    int top() {
        return mainQueue.front();
    }

    bool empty() {
        return mainQueue.empty();
    }

private:
    queue<int> mainQueue;
    queue<int> tempQueue;
};

int main() {

    StackUsingQueues stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << "Top element: " << stack.top() << endl; // Output: 5

    stack.pop();

    cout << "Top element after pop: " << stack.top() << endl; // Output: 4

    stack.push(6);

    cout << "Top element: " << stack.top() << endl; // Output: 6

    system("pause");
    return 0;
}
