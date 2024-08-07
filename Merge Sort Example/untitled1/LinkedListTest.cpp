#include "LinkedListTest.h"

void LinkedListTest::runTests() {
    testStack();
    testQueue();
}

void LinkedListTest::testStack() {
    Stack<int> stack;
    std::cout << "Testing Stack:" << std::endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "After pushing 1, 2, 3:" << std::endl;
    printStack(stack);

    stack.pop();
    std::cout << "After popping:" << std::endl;
    printStack(stack);

    std::cout << std::endl;
}

void LinkedListTest::testQueue() {
    Queue<int> queue;
    std::cout << "Testing Queue:" << std::endl;

    queue.insert(1);
    queue.insert(2);
    queue.insert(3);

    std::cout << "After inserting 1, 2, 3:" << std::endl;
    printQueue(queue);

    queue.remove();
    std::cout << "After removing one element:" << std::endl;
    printQueue(queue);

    std::cout << std::endl;
}

void LinkedListTest::printStack(Stack<int>& stack) {
    // Temporarily copying the stack to print and maintain original
    Stack<int> tempStack;
    while (!stack.isEmpty()) {
        int* val = stack.top();
        if (val) {
            std::cout << *val << " ";
            tempStack.push(*val); // Push to tempStack to maintain original order
            stack.pop();
        }
    }
    // Restoring the original stack from tempStack
    while (!tempStack.isEmpty()) {
        int* val = tempStack.top();
        if (val) {
            stack.push(*val);
            tempStack.pop();
        }
    }
    std::cout << std::endl;
}

void LinkedListTest::printQueue(Queue<int>& queue) {
    // Since removing from queue is destructive, we just print as we dequeue
    Queue<int> tempQueue;
    while (!queue.isEmpty()) {
        int* front = queue.next();
        if (front) {
            std::cout << *front << " ";
            tempQueue.insert(*front);
            queue.remove();
        }
    }

    // Restoring the original queue from tempQueue
    while (!tempQueue.isEmpty()) {
        int* val = tempQueue.next();
        if (val) {
            queue.insert(*val);
            tempQueue.remove();
        }
    }
    std::cout << std::endl;
}