template <typename T>
class SNode {
public:
    T data; // The data stored in the node
    SNode* next; // Pointer to the next node

    // Constructor
    SNode(T dataValue, SNode* nextNode = nullptr) : data(dataValue), next(nextNode) {}

    // Destructor
    ~SNode() {
        // Implement any cleanup necessary for the node, if required.
        // For basic data types and pointers, this might be empty.
    }
};