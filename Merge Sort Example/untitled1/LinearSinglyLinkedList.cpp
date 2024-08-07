
#include "SNode.h"
template <typename T>
class LinearSinglyLinkedList {
private:
    SNode<T>* head;

public:
    LinearSinglyLinkedList() : head(nullptr) {}

    ~LinearSinglyLinkedList() {
        deleteList();
    }

    bool IsEmptyList() const {
        return head == nullptr;
    }

    void insertElmAtEnd(T newData) {
        SNode<T>* newNode = new SNode<T>(newData);
        if (head == nullptr) {
            head = newNode;
        } else {
            SNode<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool removefromFront() {
        if (head == nullptr) {
            return false;
        }
        SNode<T>* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    void copyList(const LinearSinglyLinkedList<T>& otherList) {
        deleteList(); // Clear current list

        SNode<T>* current = otherList.head;
        while (current != nullptr) {
            insertElmAtEnd(current->data);
            current = current->next;
        }
    }

    void deleteList() {
        SNode<T>* current = head;
        while (current != nullptr) {
            SNode<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    T* nextElm() {
        if (head && head->next) {
            return &(head->next->data);
        }
        return nullptr; // If there is no next element
    }

    T* addElmAtFront() {
        if (head != nullptr) {
            return &(head->data);
        } else {
            return nullptr; // List is empty
        }
    }
};