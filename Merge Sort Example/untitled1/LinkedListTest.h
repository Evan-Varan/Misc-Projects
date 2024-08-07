#pragma once
#include <iostream>
#include "Stack.h"
#include "Queue.h"

class LinkedListTest {
public:
    void runTests();
private:
    void testStack();
    void testQueue();
    void printStack(Stack<int>& stack);
    void printQueue(Queue<int>& queue);
};