#include <iostream>
#include "Stack.h"
#include "Queue.h"

class Test {
private:
    Stack<int> stack;
    Queue<int> queue;

public:
    void storeData() {
        int data;
        std::cout << "Enter integers to store in stack and queue (end with -1): ";
        while (true) {
            std::cin >> data;
            if (data == -1) break;
            stack.push(data);
            queue.insert(data);
        }
    }

    void printOutStack() {
        std::cout << "Stack contents (top to bottom): ";
        while (!stack.isEmpty()) {
            int* top = stack.top();
            if (top) {
                std::cout << *top << " ";
                stack.pop();
            }
        }
        std::cout << std::endl;
    }

    void printOutQueue() {
        std::cout << "Queue contents (front to back): ";
        while (!queue.isEmpty()) {
            int* front = queue.next();
            if (front) {
                std::cout << *front << " ";
                queue.remove();
            }
        }
        std::cout << std::endl;
    }

    // For demonstration: Print both stack and queue contents.
    void printOut() {
        printOutQueue(); // Queue will be printed first as it was filled first
        printOutStack(); // Stack will be printed in reverse order
    }
};