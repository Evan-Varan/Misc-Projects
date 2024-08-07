#pragma once

template <typename T>
class SNode {
public:
    T data;
    SNode* next;

    SNode(T dataValue, SNode* nextNode = nullptr) : data(dataValue), next(nextNode) {}
};