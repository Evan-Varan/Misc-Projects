// Queue.h
#pragma once
#include "LinearSinglyLinkedList.h"

template <typename T>
class Queue {
private:
    LinearSinglyLinkedList<T> list; // Uses LinearSinglyLinkedList for storage

public:
    Queue();
    void insert(T data);
    bool remove();
    T* next();
    bool isEmpty() const;
};