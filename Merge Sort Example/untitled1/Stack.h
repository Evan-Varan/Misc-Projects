// Stack.h
#pragma once
#include "LinearSinglyLinkedList.h"

template <typename T>
class Stack {
private:
    LinearSinglyLinkedList<T> list; // Utilizing the previously defined LinearSinglyLinkedList

public:
    Stack(); // Constructor

    void push(T data); // Pushes data onto the stack

    bool pop(); // Removes the top element from the stack

    T* top(); // Returns the top element of the stack

    bool isEmpty() const; // Checks if the stack is empty
};
