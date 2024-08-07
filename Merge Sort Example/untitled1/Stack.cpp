#include "Stack.h"
#include <string>

// Template definitions
template <typename T>
Stack<T>::Stack() {
    // Implementation or leave empty if not needed
}

template <typename T>
void Stack<T>::push(T data) {
    list.insertElmAtEnd(data);
}

template <typename T>
bool Stack<T>::pop() {
    return list.removefromFront();
}

template <typename T>
T* Stack<T>::top() {
    return list.addElmAtFront();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return list.IsEmptyList();
}

// Explicit instantiations
template class Stack<int>;
template class Stack<std::string>;