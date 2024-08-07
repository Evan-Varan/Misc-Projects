#include "Queue.h"
#include <string>


// Template method definitions
template <typename T>
Queue<T>::Queue() {
    // Constructor implementation
}

template <typename T>
void Queue<T>::insert(T data) {
    list.insertElmAtEnd(data);
}

template <typename T>
bool Queue<T>::remove() {
    return list.removefromFront();
}

template <typename T>
T* Queue<T>::next() {
    return list.addElmAtFront();
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return list.IsEmptyList();
}

// Explicit instantiations for types used
template class Queue<int>;
template class Queue<std::string>;